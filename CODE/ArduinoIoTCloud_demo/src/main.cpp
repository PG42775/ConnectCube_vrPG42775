#include "thingProperties.h"

void setup()
{
  // Initialize serial and wait for port to open:
  Serial.begin(115200);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();

  demo01 = 0;

}

void loop()
{
  ArduinoCloud.update();
  // Your code here

  Serial.println(demo01);
  demo01++;
  delay(1000);
}

void onDemo01Change()  {
  // Add your code here to act upon Demo01 change

}

void onResetChange()  {
  // Add your code here to act upon Reset change
  if(reset){
    demo01=0;
  }

}