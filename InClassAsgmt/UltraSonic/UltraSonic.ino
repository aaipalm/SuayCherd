#include <HCSR04.h>
HCSR04 hc(D5,D9); //initialisation class HCSR04 (trig,echo);
void setup() {
 Serial.begin(9600);
}
void loop() {
  Serial.println(hc.dist() );}
