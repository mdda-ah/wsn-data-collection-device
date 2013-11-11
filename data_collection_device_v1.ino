/*

data_collection_device_v1

"Listens" for data frames coming in to the attached 
XBee radio (which is the co-ordinator of a ZigBee network)
from nearby sensor devices (Wasmpmote v1) and sends the 
data by HTTP POST to a remote API.

2013-04-25, Alan Holding, Manchester Digital Development Agency, Manchester City Council.
2013-11-11, Published to GitHub

*/

#define MDDA_APPLICATION_NAME "data_collection_device_v1"

#include <SPI.h>
#include <Ethernet.h>
#include <XBee.h>

void(* resetFunc) (void) = 0; //declare reset function @ address 0

//  Enter the MAC address of the Ethernet shield below.
//  Newer Ethernet shields have a MAC address printed on a sticker on the shield.
//  If there is no sticker, you'll have to make up a MAC address.
byte mac[] = { 0x02, 0x3D, 0xDA, 0x30, 0x30, 0x31 };  //  MDDA001 ;)

//  Self-assigned IP address of the Arduino's Ethernet shield on Alan Holding's Mac via OS X Internet Sharing.
//  Used for testing.
//  Commented out as not needed during deployment.
//byte ip[] = { 192, 168, 2, 2 };

//  IP Address of Alan Holding's Mac via OS X Internet Sharing.
//  Used for testing.
//  Commented out as not needed during deployment.
//byte gateway[] = { 192, 168, 2, 1 };

//  IP Address of the destination web server hosted the data reporting API on Alan's Mac via OS X Internet Sharing.
//  Used for testing.
//  Commented out as not used during deployment.
//byte server[] = { 192, 168, 2, 1 };

//  IP Address of destination web server on hosting the data reporting API
//  Commented out as different per deployment.
//byte server[] = {x, x, x, x};  //  Put the IP address here.

//  Hostname where the data reporting API is located.
//  Commented out as different per deployment.
//String host = "simple-sensor-api.alan.dev";    //  Example on Alan Holding's Mac, used for testing purposes.
//String host = "[INSERT YOUR DOMAIN NAME HERE";

int deviceStatus = 0;
int counter = 0;
String postData,uri,waspdata;

//  **********  XBee stuff
XBee xbee = XBee();
XBeeResponse response = XBeeResponse();
ZBRxResponse rx = ZBRxResponse();
ModemStatusResponse msr = ModemStatusResponse();

//  Initialize the Ethernet client library.
EthernetClient client;

//  **********  Here we go!
void setup() {
//  Slight pause to give the Arduino time to wake up.
  delay(50);

  xbee.begin(38400);
  Serial.begin(38400);
  delay(500);
  
  Serial.print(MDDA_APPLICATION_NAME);
  Serial.println(" started");

//  Start the Ethernet connection and test if we've been given an IP address by the DHCP server.
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP. Restarting application.");
    delay(1000);
    resetFunc();  //call reset
  } else {
//  Connected, so give the Ethernet connection a second to settle.
    delay(1000);
    Serial.print("Connected to network with IP address: ");
    Serial.println(Ethernet.localIP());
  }

}

//  **********  Here we go!
void loop() {
  xbee.readPacket(100);
  if (xbee.getResponse().isAvailable()) {
    if (xbee.getResponse().getApiId() == ZB_RX_RESPONSE) {
      xbee.getResponse().getZBRxResponse(rx);
      waspdata = "";
      //  i = 6 to skip the first six bytes added to ZigBee frame by Libelium API on Waspmote, which we're not interested in at the moment.
      for (int i = 6; i < rx.getDataLength(); i++) {
        waspdata += char(rx.getData(i));
      }
      Serial.println(waspdata);
      prepareData();
      attemptToSendDataViaEthernet();
      postData="";
    }
  } else if (xbee.getResponse().isError()) {
    Serial.print("oh no - error code:");
    Serial.println(xbee.getResponse().getErrorCode());
  }
  //rx.reset();
  delay(100);
}




