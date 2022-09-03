
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
    Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  mySerial.begin(9600);

}

void loop() {
  Serial.println("CEALTOR,26.7,6.8");
  mySerial.println("CEALTOR,26.7,6.8");
  delay(1000);
}
