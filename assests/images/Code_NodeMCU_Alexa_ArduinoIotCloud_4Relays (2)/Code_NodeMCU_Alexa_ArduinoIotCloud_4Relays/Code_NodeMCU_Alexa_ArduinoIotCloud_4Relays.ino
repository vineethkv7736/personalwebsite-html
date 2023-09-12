/**********************************************************************************
 *  TITLE: Arduino IoT Cloud control 4 Relays using NodeMCU
 *  Click on the following links to learn more. 
 *  YouTube Video: https://youtu.be/UtReFcOLJx8
 *  Related Blog : https://iotcircuithub.com/esp8266-projects/
 *  by Tech StudyCell
 *  Preferences--> Aditional boards Manager URLs : 
 *  https://dl.espressif.com/dl/package_esp32_index.json, http://arduino.esp8266.com/stable/package_esp8266com_index.json
 *  
 *  Download Board ESP8266 NodeMCU : https://github.com/esp8266/Arduino
 *  Download the libraries
 *  ArduinoIoTCloud Library with all the dependencies
 **********************************************************************************/


#include "arduino_secrets.h"
#include "thingProperties.h"

// define the GPIO connected with Relays and switches
#define RelayPin1 5  //D1
#define RelayPin2 4  //D2
#define RelayPin3 14 //D5
#define RelayPin4 12 //D6

#define SwitchPin1 10  //SD3
#define SwitchPin2 0   //D3 
#define SwitchPin3 13  //D7
#define SwitchPin4 3   //RX

#define wifiLed   16   //D0

int toggleState_1 = 0; //Define integer to remember the toggle state for relay 1
int toggleState_2 = 0; //Define integer to remember the toggle state for relay 2
int toggleState_3 = 0; //Define integer to remember the toggle state for relay 3
int toggleState_4 = 0; //Define integer to remember the toggle state for relay 4

void manual_control() 
{
  //Manual Switch Control
  if ((digitalRead(SwitchPin1) == LOW)&&toggleState_1==0)
  {
    digitalWrite(RelayPin1, LOW); // turn on relay 1
        toggleState_1 = 1;
  }
  else
  {
    digitalWrite(RelayPin1, HIGH); // turn on relay 1
        toggleState_1 = 0;
  }
//1
  if ((digitalRead(SwitchPin2) == LOW)&&toggleState_2==0)
  {
    digitalWrite(RelayPin2, LOW); // turn on relay 1
        toggleState_2 = 1;
  }
  else
  {
    digitalWrite(RelayPin2, HIGH); // turn on relay 1
        toggleState_2 = 0;
  }
//2
  if ((digitalRead(SwitchPin3) == LOW)&&toggleState_3==0)
  {
    digitalWrite(RelayPin3, LOW); // turn on relay 1
        toggleState_3 = 1;
  }
  else
  {
    digitalWrite(RelayPin3, HIGH); // turn on relay 1
        toggleState_3 = 0;
  }
//3
  if ((digitalRead(SwitchPin4) == LOW)&&toggleState_4==0)
  {
    digitalWrite(RelayPin4, LOW); // turn on relay 1
        toggleState_4 = 1;
  }
  else
  {
    digitalWrite(RelayPin4, HIGH); // turn on relay 1
        toggleState_4 = 0;
  }
}

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);
  pinMode(RelayPin4, OUTPUT);

  pinMode(wifiLed, OUTPUT);

  pinMode(SwitchPin1, INPUT_PULLUP);
  pinMode(SwitchPin2, INPUT_PULLUP);
  pinMode(SwitchPin3, INPUT_PULLUP);
  pinMode(SwitchPin4, INPUT_PULLUP);

  //During Starting all Relays should TURN OFF
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(RelayPin3, HIGH);
  digitalWrite(RelayPin4, HIGH);

  digitalWrite(wifiLed, HIGH);  //Turn OFF WiFi LED
}

void loop() 
{
  
  ArduinoCloud.update();
  
  manual_control(); //Control relays manually

  if (WiFi.status() != WL_CONNECTED)
  {
    digitalWrite(wifiLed, HIGH); 
    manual_control();
  }
  else
  {
    digitalWrite(wifiLed, LOW); manual_control();
  }
}

void onSwitch1Change() {
  if (switch1 == 1)
  {
    digitalWrite(RelayPin1, LOW);
    Serial.println("Device1 ON");
    toggleState_1 = 1;
  }
  else
  {
    digitalWrite(RelayPin1, HIGH);
    Serial.println("Device1 OFF");
    toggleState_1 = 0;
  }
}

void onSwitch2Change() {
  if (switch2 == 1)
  {
    digitalWrite(RelayPin2, LOW);
    Serial.println("Device2 ON");
    toggleState_2 = 1;
  }
  else
  {
    digitalWrite(RelayPin2, HIGH);
    Serial.println("Device2 OFF");
    toggleState_2 = 0;
  }
}

void onSwitch3Change() {
  if (switch3 == 1)
  {
    digitalWrite(RelayPin3, LOW);
    Serial.println("Device2 ON");
    toggleState_3 = 1;
  }
  else
  {
    digitalWrite(RelayPin3, HIGH);
    Serial.println("Device3 OFF");
    toggleState_3 = 0;
  }
}

void onSwitch4Change() {
  if (switch4 == 1)
  {
    digitalWrite(RelayPin4, LOW);
    Serial.println("Device4 ON");
    toggleState_4 = 1;
  }
  else
  {
    digitalWrite(RelayPin4, HIGH);
    Serial.println("Device4 OFF");
    toggleState_4 = 0;
  }
}
