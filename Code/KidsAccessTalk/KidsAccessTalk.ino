#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial mySoftwareSerial(3, 2); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

int button1 = 4;
int button2 = 5;
int button3 = 6;
int button4 = 7;
int button5 = 8;

void setup() {
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(button5, INPUT_PULLUP);

  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  delay(1000);

  Serial.println();
  Serial.println("DFPlayer Mini Demo");
  Serial.println("Initializing DFPlayer...");

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("Unable to begin:");
    Serial.println("1.Please recheck the connection!");
    Serial.println("2.Please insert the SD card!");
    while (true);
  }
  Serial.println(F("DFPlayer Mini online."));

  myDFPlayer.setTimeOut(500);

  // Set volume
  myDFPlayer.volume(29); //Set volume value (0~30).
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);

  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  //digitalWrite(button1, LOW);
}

void loop() {
  int buttonState1 = digitalRead(button1);
  int buttonState2 = digitalRead(button2);
  int buttonState3 = digitalRead(button3);
  int buttonState4 = digitalRead(button4);
  int buttonState5 = digitalRead(button5);

  if (buttonState1 ==  LOW) {
    Serial.println("1 kepencet");
    myDFPlayer.playMp3Folder(1); // Play the sound associated with button1
    delay(2000);
  }
  else if (buttonState2 == LOW) {
    Serial.println("2 kepencet");
    myDFPlayer.playMp3Folder(2); // Play the sound associated with button2
    delay(2000);
  }
  else if (buttonState3 == LOW) {
    Serial.println("3 kepencet");
    myDFPlayer.playMp3Folder(3); // Play the sound associated with button3
    delay(2000);
  }
  else if (buttonState4 == LOW) {
    Serial.println("4 kepencet");
    myDFPlayer.playMp3Folder(4); // Play the sound associated with button4
    delay(2000);
  }
  else if (buttonState5 == LOW) {
    Serial.println("5 kepencet");
    myDFPlayer.playMp3Folder(5); // Play the sound associated with button5
    delay(2000);
  }
}
