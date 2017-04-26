#include <SamVESC.h>

SamVESC vesc1(115200);

void setup() {
  vesc1.Attach(Serial2);

}

void loop() {
  for (int i = 0; i < 30; i++)
  {
    vesc1.SetCurrent(5);
    delay(100);
  }
  for (int i = 0; i < 30; i++)
  {
    vesc1.SetCurrent(-5);
    delay(100);
  }
  // put your main code here, to run repeatedly:

}