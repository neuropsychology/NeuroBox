// the setup routine runs once when you press reset:
int index, sensorValue;
unsigned long cur_time, prev_time, diff_time, deadline;
unsigned long duration, max_duration, min_duration;
unsigned int period_usec, hz, threshold;


// setup routine
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  hz = 2500;

  // calibrate and change threshold according to the experiment
  threshold = 100;

  period_usec = 1000000 / hz;
  Serial.println(period_usec);

  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);

  max_duration = 0;
  min_duration = 1000000;
  deadline = micros();
}


// the loop routine runs over and over again forever:
void loop() {
  cur_time = micros();

  // todo: handle rollover
  if(deadline < cur_time) {
    deadline = deadline + period_usec;
   
    // main work
    sensorValue = analogRead(A0);
    if (sensorValue < threshold) {
      digitalWrite(2, LOW);
      digitalWrite(13, HIGH);
    }
    else {
      digitalWrite(2, HIGH);
      digitalWrite(13, LOW);
    }

    // report and inspection
    index = (index + 1) % (3 * hz);
    diff_time = cur_time - prev_time;
    prev_time = cur_time;
    if (diff_time > max_duration) {
      max_duration = diff_time;
    } else if (diff_time < min_duration) {
      min_duration = diff_time;
    }

    if (index == 0) {
      /* Serial.println(index); */
      /* Serial.println(max_duration); */
      /* Serial.println(min_duration); */
      Serial.println("Analog read: ");
      Serial.println(sensorValue);
      /* Serial.println(cur_time); */
      max_duration = 0;
      min_duration = 1000000;
      }

  }	
}
