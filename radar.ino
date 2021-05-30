#include "function.h"
void setup() {
 Serial.begin (9600); 
 pinMode(pin_diod_digital, OUTPUT); 
 pinMode(pin_radar_trig, OUTPUT); 
 pinMode(pin_radar_echo, INPUT);
}

void loop() {
 radar();
}
