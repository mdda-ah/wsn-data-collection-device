//  Function which attempts to send data to the web host via the Ethernet connection/
void attemptToSendDataViaEthernet() {
  Serial.println("Connecting");
  if (!client.connected()) {
    if (client.connect(server,80)) {
      Serial.print("Connected with IP address: ");
      Serial.println(Ethernet.localIP());
  
//  Send data to host using HTTP POST
      client.print( "POST " );
      client.print( uri );
      client.println( " HTTP/1.1" );
      client.println( "Host: " + host );
      client.println( "Content-Type: application/x-www-form-urlencoded" );
      client.println( "Connection: close" );
      client.print( "Content-Length: " );
      client.println( postData.length() );
      client.println();
      client.print( postData );
      client.println();

//      client.print("GET ");
//      client.println("/ping HTTP1/1");
//      client.println("Accept: text/html");
//      client.println( "Host: " + host );
//      client.println();  

//  This is dangerous and very messy and could lead to an infinite loop if the web server does not respond, hence the timeout.
      int timeout = 0;
      while(timeout < 10) {
        delay(1000);
        Serial.println("Waiting for client data");
        if (client.available()) {
//  Print response from server
          while(client.available()){
            char c = client.read();
            Serial.print(c);
          }
          break;
        } else {
          timeout++;
        }          
      }

      Serial.println();
      Serial.println("Disconnecting");
      delay(5);
      client.flush();
      delay(5);
      client.stop();
  
    } else {
      Serial.println("Connection failed.");
    }
  }
  
  Serial.println("-----");
}

