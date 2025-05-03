#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);
float defaulty = 0.0;
float defaultz = 0.0;
float roll = 0.0;
float pitch = 0.0;
unsigned long last = 0;
unsigned long blinkDuration = 0;
int blink = 0;

void setup() {
  pinMode(5, OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  mpu6050.update();
  defaulty = mpu6050.getAngleY(); // pitch acuan
  defaultz = mpu6050.getAngleZ(); // roll acuan
}

void loop() {
  // update data
  mpu6050.update();
  roll = mpu6050.getAngleZ() - defaultz;
  pitch = mpu6050.getAngleY() - defaulty;

  // wrap-around kalo nilai mutlaknya melebihi 180 derajat (dari -181 ke +179 dan sebaliknya)
  if (roll > 180) roll -= 360;
  else if (roll < -180) roll += 360;
  if (pitch > 180) pitch -= 360;
  else if (pitch < -180) pitch += 360;

  if (abs(roll) >= 90 || abs(pitch) >= 90) {
    // LED dalam mode kedip, dihitung interval kedip berdasarkan sudut
    blink = 1;
    blinkDuration = (unsigned long)(850 - (35*max(abs(roll), abs(pitch))/9 ));
  } else blink = 0; // LED mati

  if (blink) {
    // interval kedipan sudah terlewati, LED berubah state dari nyala ke mati atau mati ke nyala
    if (millis() - last >= blinkDuration) {
      last = millis();
      digitalWrite(5, !digitalRead(5));
    }
  } else if (millis() - last >= 500) digitalWrite(5, LOW);

  // Pengawasan pembacaan sudut dengan serial monitor
  Serial.print("Pitch : ");
  Serial.print(pitch);
  Serial.print("\tRoll : ");
  Serial.println(roll);
}
