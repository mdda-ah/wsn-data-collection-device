void prepareData() {

  int commaCounter = 0;
  int commaPosition = 0;
  int previousPosition = 0;
//  String device,sensor,datetime,reading;
  String device,sensor,reading,minreading,maxreading,nodecounter;

//  Serial.print("Device ID is: ");
  commaPosition = waspdata.indexOf(",",previousPosition);
  device = waspdata.substring(previousPosition,commaPosition);
  previousPosition = commaPosition+1;
  
//  Serial.print("Sensor ID is: ");
  commaPosition = waspdata.indexOf(",",previousPosition);
  sensor = waspdata.substring(previousPosition,commaPosition);
  previousPosition = commaPosition+1;
  
//  Serial.print("Datetime is: ");
//  commaPosition = waspdata.indexOf(",",previousPosition);
//  datetime = waspdata.substring(previousPosition,commaPosition);
//  previousPosition = commaPosition+1;

//  Serial.print("Reading is: ");
  commaPosition = waspdata.indexOf(",",previousPosition);
  reading = waspdata.substring(previousPosition,commaPosition);
  previousPosition = commaPosition+1;
  
//  Serial.print("Min Reading is: ");
  commaPosition = waspdata.indexOf(",",previousPosition);
  minreading = waspdata.substring(previousPosition,commaPosition);
  previousPosition = commaPosition+1;

//  Serial.print("Max Reading is: ");
  commaPosition = waspdata.indexOf(",",previousPosition);
  maxreading = waspdata.substring(previousPosition,commaPosition);
  previousPosition = commaPosition+1;

//  Serial.print("Sensor node loop counter is: ");
  commaPosition = waspdata.indexOf(",",previousPosition);
  nodecounter = waspdata.substring(previousPosition,commaPosition);
  previousPosition = commaPosition+1;

  counter++;
//  dataForMCPAPI = "device_id=" + device + "&sensor_id=" + sensor + "&datetime=" + datetime + "&reading=" + reading;
//  uri = "/device/store/" + device;

  postData = "d_id=" + device + "&s_id=" + sensor + "&r=" + reading + "&minr=" + minreading + "&maxr=" + maxreading + "&ncount=" + nodecounter + "&ccount=" + counter;
  uri = "/reading";
  
  Serial.println(postData);
  Serial.println(uri);
  
 }

