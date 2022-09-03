#include <SoftwareSerial.h>

String msg_split[4];
String serial_buff, header, s_suhu, s_ph;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);
  
  mySerial.begin(9600);
}

void loop() { // run over and over
  if (mySerial.available()) {
    serial_buff=mySerial.readStringUntil('\n');
    //Serial.print(serial_buff);
    split(serial_buff,',');

    header = msg_split[0];
    s_suhu = msg_split[1];
    s_ph = msg_split[2];
    Serial.println(header);
    Serial.print("Suhu:");
    Serial.println(s_suhu);
    Serial.print("pH:");
    Serial.println(s_ph);
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

void split(String objectm, char delimiter) {
  byte i = 0;
  String temp = "";
  int commaPosition;
  do {
    commaPosition = objectm.indexOf(delimiter);
    if (commaPosition != -1) {
      temp = objectm.substring(0, commaPosition);
      objectm = objectm.substring(commaPosition + 1, objectm.length());
    }
    else {
      if (objectm.length() > 0) {
        temp = objectm;
      }
    }
    msg_split[i] = temp;
    i++;
  }
  while (commaPosition >= 0);
}
