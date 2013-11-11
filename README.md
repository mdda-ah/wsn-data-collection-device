#wsn-data-collection-device

Arduino compatible sketch for data collection devices on MDDA Wireless Sensor Network.

* Listens for incoming ZigBee frames on an attached XBee radio, which is acting as the coordinator of a ZigBee network.
* Parses the ZigBee into an HTTP Post to a remote API.
* POSTs the data to the remote API.
* Repeats.

## Background

This software was developed as part of the [Smart IP](http://www.smart-ip.eu/) project to support the trial of an on-street Wireless Sensor Network in parts of Manchester, UK.

## Requirements

[Arduino](http://arduino.cc) compatible board - we used the [Freetronics EtherTen](http://www.freetronics.com/products/etherten) for the in-built Ethernet port and the ability to add a Power over Ethernet adaptor to keep the physical size of the device small.
ZigBee radio (XBee Pro S2)

## Installation

Clone / download the files to your Arduino compatible board's sketch directory. You can find this directory via Preferences > Sketchbook location in the Arduino IDE. Be careful not to overwrite your Arduino's libraries directory.

You will also need to download v0.3 of the [xbee-arduino](https://code.google.com/p/xbee-arduino/) library by Andrew Rapp.

You will need to configure ZigBee radios that you use in your network to talk to each other.

## License

This program is free software: you can redistribute it and/or modify it under the terms of the version 3 GNU General Public License as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see [http://www.gnu.org/licenses/](http://www.gnu.org/licenses/).

The above applies to the files data_collection_device_v1.ino, attemptToSend.ino, prepareData.ino and sdStore.ino.

Thanks for reading!