//void storeDataOnSDCard() {
//
//  File myFile;
//
//  Serial.println("Initializing SD card");
//  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
//  // Note that even if it's not used as the CS pin, the hardware SS pin 
//  // (10 on most Arduino boards, 53 on the Mega) must be left as an output 
//  // or the SD library functions will not work. 
//  pinMode(10, OUTPUT);
//   
//  if (!SD.begin(4)) {
//    Serial.println("initialization failed!");
//    
//    //  Note problem!
//    deviceStatus |= SDCARD_NOT_RESPONDING;
//    
//    return;
//  }
//  Serial.println("initialization done.");
//  
//  // open the file. note that only one file can be open at a time,
//  // so you have to close this one before opening another.
//  myFile = SD.open("archive.txt", FILE_WRITE);
//  
//  // if the file opened okay, write to it:
//  if (myFile) {
//    Serial.print("Writing to archive.txt");
//    myFile.println(data);
//    // close the file:
//    myFile.close();
//    Serial.println("done.");
//  } else {
//    // if the file didn't open, print an error:
//    Serial.println("error opening archive.txt");
//    //  Note the problem!
//    deviceStatus |= SDCARD_FILE_OPEN_ERROR;
//
//  }
//  
//  // re-open the file for reading:
//  myFile = SD.open("archive.txt");
//  if (myFile) {
//    Serial.println("archive.txt:");
//    
//    // read from the file until there's nothing else in it:
//    while (myFile.available()) {
//    	Serial.write(myFile.read());
//    }
//    // close the file:
//    myFile.close();
//  } else {
//  	// if the file didn't open, print an error:
//    //  Note the problem!
//    Serial.println("error opening archive.txt");
//    deviceStatus |= SDCARD_FILE_OPEN_ERROR;
//  }
//
//}
//

