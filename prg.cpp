#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver(0x40);

// pulse range
int minPulse = 150;
int maxPulse = 600;

int toPulse(int angle) {
  return map(angle, 0, 180, minPulse, maxPulse);
}

// 🔥 Flip direction for LEFT side (CH3, CH5)
int fixLeft(int angle) {
  return 180 - angle;
}

void setup() {
  Wire.begin(21, 22);
  pca.begin();
  pca.setPWMFreq(50);

  delay(1000);
}

void loop() {

  // ===== POSITION 1 (90°) =====

  // LEFT LEG (CH3, CH5)
  pca.setPWM(3, 0, toPulse(fixLeft(90)));
  pca.setPWM(5, 0, toPulse(fixLeft(90)));
  delay(800);

  // RIGHT LEG (CH4, CH6)
  pca.setPWM(4, 0, toPulse(90));
  pca.setPWM(6, 0, toPulse(90));
  delay(1200);


  // ===== POSITION 2 (60°) =====

  // LEFT LEG
  pca.setPWM(3, 0, toPulse(fixLeft(60)));
  pca.setPWM(5, 0, toPulse(fixLeft(60)));
  delay(800);

  // RIGHT LEG
  pca.setPWM(4, 0, toPulse(120));  // 🔥 flipped
  pca.setPWM(6, 0, toPulse(60));
  delay(1200);


  // ===== POSITION 3 (120°) =====

  // LEFT LEG
  pca.setPWM(3, 0, toPulse(fixLeft(120)));
  pca.setPWM(5, 0, toPulse(fixLeft(120)));
  delay(800);

  // RIGHT LEG
  pca.setPWM(4, 0, toPulse(60));   // 🔥 flipped
  pca.setPWM(6, 0, toPulse(120));
  delay(1200);
}
