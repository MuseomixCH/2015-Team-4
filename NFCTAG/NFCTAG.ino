#include <SPI.h>
#include "PN532_SPI.h"
#include "PN532.h"
#include "NfcAdapter.h"
int Blinkmgnd = 16 ;
int Blinkmvdd = 17 ;

 
PN532_SPI interface(SPI, 10); // create a PN532 SPI interface with the SPI CS terminal located at digital pin 10
NfcAdapter nfc = NfcAdapter(interface); // create an NFC adapter object
 
void setup(void) {
  
    Serial.begin(115200); // begin serial communication
    Serial.println("NDEF Reader");
    nfc.begin(); // begin NFC communication
pinMode(Blinkmgnd,OUTPUT);
pinMode(Blinkmvdd,OUTPUT);
digitalWrite(Blinkmvdd, HIGH);   // sets the BlinkM on
digitalWrite(Blinkmgnd, LOW);    // sets the BlinkM on
digitalWrite(Blinkmvdd, LOW);   // sets the BlinkM on     
}
 
void loop(void) {

    
    if (nfc.tagPresent()) // Do an NFC scan to see if an NFC tag is present
    {
      //Serial.println("\nScan an NFC tag\n");
        NfcTag tag = nfc.read(); // read the NFC tag into an object, nfc.read() returns an NfcTag object.
        tag.print(); // prints the NFC tags type, UID, and NDEF message (if available)
        digitalWrite(Blinkmvdd, HIGH);   // sets the BlinkM on
        delay(3000);
        digitalWrite(Blinkmvdd, LOW);   // sets the BlinkM off
        //String output = tag.print();
     //   File script = FileSystem.open("/tmp/collecte.txt", FILE_APPEND);
     //   String output = tag.getUidString();
     //   script.print(output);
    }
    delay(100); // wait half a second (500ms) before scanning again (you may increment or decrement the wait time)
}
