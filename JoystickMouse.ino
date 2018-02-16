#include <DigiMouse.h>

float mspeed = 1.1;

void setup() {
  pinMode(1, INPUT);
  DigiMouse.begin();
}

void loop() {
  int x = analogRead(A1);
  int y = analogRead(A0);

  DigiMouse.moveX(mspeed*((x-512)^2)*0.01);//425
  DigiMouse.moveY(mspeed*((y-512)^2)*0.01);//415

  if(digitalRead(1)==LOW && mspeed-0.25>0){
    delay(500);
    mspeed-=0.25;
  }else if(digitalRead(1)==LOW){
    delay(500);
    mspeed=1;
  }
 
  DigiMouse.update();

}
