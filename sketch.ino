#include <EducationShield.h>

IMU imu;
int piezoPin = 8


void setup() {
  Serial.begin(9600);  
  imu.begin();
  pinMode(piezoPin, OUTPUT);
}

void loop() {
  imu.run();
  
  int pitch = imu.getPitch();
  int roll = imu.getRoll();
  
  Serial.print(pitch);
  Serial.print("\t");
  Serial.println(roll);
  
  pitch = abs(pitch);
  roll = abs(roll);

  int frequency = pitch  + roll;
  frequency = frequency / 2;
  frequency = map(frequency, 0, 360, 0, 1000);

  if (frequency > 50) {
    tone(piezoPin, frequency);
  } else {
    noTone(piezoPin);
  }
}


