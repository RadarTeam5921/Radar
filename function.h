int pin_radar_echo = 12; 
int pin_radar_trig = 11; 
int pin_motor_in1 = 2; 
int pin_motor_in2 = 3; 
int pin_motor_in3 = 4; 
int pin_motor_in4 = 5; 
int pin_diod_digital = 8; 
int pin_zummer_analog = 6; 
int flag_for_motor = 0; 
int dl = 5; 
int ledState = LOW; 
unsigned long previousMillis = 0; 
const long interval = 100; 
void diod_blink_on() { 
 unsigned long currentMillis = millis(); 
 if (currentMillis - previousMillis >= interval) { 
 previousMillis = currentMillis; 
 if (ledState == LOW) { 
 ledState = HIGH; 
 } else { 
 ledState = LOW; 
 } 
 digitalWrite(pin_diod_digital, ledState); 
 } 
} 
void diod_blink_off() { 
 digitalWrite(pin_diod_digital, LOW); 
} 
void zummer_on() { 
 analogWrite(pin_zummer_analog, 50); 
} 
void zummer_off() { 
 analogWrite(pin_zummer_analog, 0); 
} 
void right() { 
 digitalWrite(pin_motor_in1, HIGH); 
 digitalWrite(pin_motor_in2, LOW); 
 digitalWrite(pin_motor_in3, LOW); 
 digitalWrite(pin_motor_in4, HIGH); 
 delay(dl); 
 
 digitalWrite(pin_motor_in1, LOW); 
 digitalWrite(pin_motor_in2, LOW); 
 digitalWrite(pin_motor_in3, HIGH); 
 digitalWrite(pin_motor_in4, HIGH); 
 delay(dl); 
 
 digitalWrite(pin_motor_in1, LOW); 
 digitalWrite(pin_motor_in2, HIGH); 
 digitalWrite(pin_motor_in3, HIGH); 
 digitalWrite(pin_motor_in4, LOW); 
 delay(dl); 
 
 digitalWrite(pin_motor_in1, HIGH); 
 digitalWrite(pin_motor_in2, HIGH); 
 digitalWrite(pin_motor_in3, LOW); 
 digitalWrite(pin_motor_in4, LOW); 
 delay(dl); 
} 
void left() { 
 digitalWrite(pin_motor_in1, HIGH); 
 digitalWrite(pin_motor_in2, HIGH); 
 digitalWrite(pin_motor_in3, LOW); 
 digitalWrite(pin_motor_in4, LOW); 
 delay(dl); 
 
 digitalWrite(pin_motor_in1, LOW); 
 digitalWrite(pin_motor_in2, HIGH); 
 digitalWrite(pin_motor_in3, HIGH); 
 digitalWrite(pin_motor_in4, LOW); 
 delay(dl); 
 
 digitalWrite(pin_motor_in1, LOW); 
 digitalWrite(pin_motor_in2, LOW); 
 digitalWrite(pin_motor_in3, HIGH); 
 digitalWrite(pin_motor_in4, HIGH); 
 delay(dl); 
 
 digitalWrite(pin_motor_in1, HIGH); 
 digitalWrite(pin_motor_in2, LOW); 
 digitalWrite(pin_motor_in3, LOW); 
 digitalWrite(pin_motor_in4, HIGH); 
 delay(dl); 
}
void motor_on() { 
 if(flag_for_motor==0){ 
 for(int i =0; i <256; i++) { 
 if(i % 16 == 0) radar(); 
 left(); 
 } 
 flag_for_motor=1; 
 } 
 else { 
 for(int i =0; i <256; i++) { 
 if(i % 16 == 0) radar();
 right(); 
 } 
 flag_for_motor=0; 
 } 
}
void motor_off() { 
 digitalWrite(pin_motor_in1, LOW); 
 digitalWrite(pin_motor_in2, LOW); 
 digitalWrite(pin_motor_in3, LOW); 
 digitalWrite(pin_motor_in4, LOW); 
} 
int dalnomer() { 
 int duration, cm; 
 digitalWrite(pin_radar_trig, LOW); 
 delayMicroseconds(2); 
 digitalWrite(pin_radar_trig, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(pin_radar_trig, LOW); 
 duration = pulseIn(pin_radar_echo, HIGH); 
 cm = duration / 58; 
 delay(100); 
 return cm; 
} 
void radar() {
 int duration, cm; 
 digitalWrite(pin_radar_trig, LOW); 
 delayMicroseconds(2); 
 digitalWrite(pin_radar_trig, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(pin_radar_trig, LOW); 
 duration = pulseIn(pin_radar_echo, HIGH); 
 cm = duration / 58; 
 Serial.print(cm); 
 Serial.println(" cm"); 
 if(cm < 50) { 
 zummer_on(); 
 diod_blink_on(); 
 } 
 else { 
 zummer_off(); 
 diod_blink_off(); 
 } 
 delay(10);
}
