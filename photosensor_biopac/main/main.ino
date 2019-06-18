#include <RBD_Timer.h>

// the setup routine runs once when you press reset:
int index;
unsigned long cur_time, prev_time;
unsigned long duration, max_duration, min_duration;

RBD::Timer timer;
 

// setup routine
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(2, OUTPUT);    // sets the digital pin 13 as output
  timer.setTimeout(10);
  timer.restart();
}


// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  if(timer.onRestart()) {
    int sensorValue = analogRead(A0);
    /* Serial.println("Analog read: "); */
    /* Serial.println(sensorValue); */
    
    if (sensorValue < 200) {
      digitalWrite(2, LOW);
    }
    else {
      digitalWrite(2, HIGH);
    }
  }	
}
