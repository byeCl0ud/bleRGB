/* 
Controlling LED strip with BLE AT-09
authored by @byeCl0ud
  */


#include <SoftwareSerial.h>
#include <RGBEffects.h>

int red = 4;
int green = 5;
int blue = 6;

RGBEffects rgbEffects( red; green; blue ); // digital output pins for LED strip
SoftwareSerial mySerial(2, 3); // RX, TX pins

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
  
/* setup BLE module */
//  sendCommand("AT");
  sendCommand("AT+ROLE0");
  sendCommand("AT+UUID0xFF00");
  sendCommand("AT+CHAR0xFF01");
  sendCommand("AT+NAMEbleRGB");
  Serial.println("Setup done successfully");
}

void sendCommand(const char * command){
  Serial.print("Command send :");
  Serial.println(command);
  mySerial.println(command);
  //wait some time
  delay(100);
  
  char reply[100];
  int i = 0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  //end the string
  reply[i] = '\0';
  Serial.print(reply);
  Serial.println("Reply successful");
}

int readSerial(){
  char reply[50];
  int i = 0;
  while (mySerial.available()) {
    reply[i] = mySerial.read();
    i += 1;
  }
  //end the string
  reply[i] = '\0';
  if(strlen(reply) > 0){
    Serial.println(reply);
    Serial.println("Houston we have a signal!");
  }

  /* hardcoded effect type converter to */
  return LEDmode;
}

void loop() {
char ctrl;
ctrl=readSerial(); // read commands send from iPhone
Serial.print("String read from BLE is");
Serial.println(ctrl);
if(strlen(ctrl) > 0){
  rgbEffects.setEffect(RGBEffectType ctrl);
  Serial.print("Changing effect to");
  Serial.println(ctrl);
}
delay(1000);
}
