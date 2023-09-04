#include <Servo.h>
#include <LiquidCrystal_I2C.h>
Servo frontLeft;
Servo frontRight;
Servo backLeft;
Servo backRight;

LiquidCrystal_I2C lcd(0x27, 16, 2);
int echoPin = 3, trigPin = 2;
int count = 0;
int stopSec = 1450;
int FLFwd = 1800, FRFwd = 1200, BLFwd = 1800, BRFwd = 1200;
int FLBwd = 1200, FRBwd = 1800, BLBwd = 1200, BRBwd = 1800;
// FL - Fwd > 1500
// FR - Fwd < 1500
// BL - Fwd > 1500
// BR - Fwd < 1500
void setup() {
  // put your setup code here, to run once:
  frontLeft.attach(12);
  frontRight.attach(11);
  backLeft.attach(10);
  backRight.attach(9);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);
  //  frontLeft.writeMicroseconds(stopSec);
  //  frontRight.writeMicroseconds(stopSec);
  //  backLeft.writeMicroseconds(stopSec);
  //  backRight.writeMicroseconds(stopSec);
}

void loop() {
  //   put your main code here, to run repeatedly:
  //    for (int i = 700; i <= 2300; i+=100) {
  //      frontLeft.writeMicroseconds(i);
  //      Serial.println(i);
  //      delay(1000);
  //
  //
  //    }


  //  int dist = getDistance(trigPin, echoPin);
  //  //  int dist = 0;
  //  Serial.print("Distance: ");
  //  Serial.print(dist);
  //  Serial.println(" cm");
  //  lcd.clear();
  //  lcd.setCursor(0, 0);
  //  count++;
  //  lcd.print(count);
  //  lcd.setCursor(0, 1);
  //  lcd.print(dist);
  //  delay(100);
  lcd.clear();
  lcd.print("Starting");
  delay(1200);
  int tm = 3500;
  int dly = 2000;
  for (int i = 50; i <= 100; i += 10) {
    Serial.println(i);
    goForward(tm, i);
    stopMoving(dly);

    goRight(tm, i);
    stopMoving(dly);

    goLeft(tm, i);
    stopMoving(dly);

    goBackward(tm, i);
    stopMoving(dly);
  }
  /*for (int i = 5; i >= 0; i--) {
    lcd.clear();
    lcd.print(i);
    delay(500);
    }
    int dl = 2500;
    //  goForward(dl);
    //  stopMoving();
    //  delay(500);

    goRight(dl / 4);
    stopMoving();
    delay(500);

    goForward(dl);
    stopMoving();
    delay(500);

    goLeft(dl / 4);
    stopMoving();
    delay(500);

    goBackward(dl);
    stopMoving();
    delay(500);
    lcd.clear();
    lcd.print("done");
    delay(dl);

    //  lcd.clear();
    //  lcd.print("end");
    //  delay(500);
    //  goForward(1000);

  */


}




void stopMoving() {
  frontLeft.write(1500);
  frontRight.write(1500);
  backLeft.write(1500);
  backRight.write(1500);
}
void stopMoving(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Stopping");
  frontLeft.write(1500);
  frontRight.write(1500);
  backLeft.write(1500);
  backRight.write(1500);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Stopping");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Stopping");
    lcd.setCursor(0, 1);
    lcd.print(tim);

    delay(50);
  }


}
void goForward(int dly, int spd) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Forward");
  int FLVal = map(spd, 0, 100, 1500, FLFwd);
  int FRVal = map(spd, 0, 100, 1500, FRFwd);
  int BLVal = map(spd, 0, 100, 1500, BLFwd);
  int BRVal = map(spd, 0, 100, 1500, BRFwd);
  frontLeft.write(FLVal);
  frontRight.write(FRVal);
  backLeft.write(BLVal);
  backRight.write(BRVal);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Forward- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Forward");
    lcd.setCursor(0, 1);
    lcd.print(tim);
    lcd.print(" ");
    lcd.print(spd);
    delay(50);
  }
}
void goForward(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Forward");
  frontLeft.write(FLFwd);
  frontRight.write(FRFwd);
  backLeft.write(BLFwd);
  backRight.write(BRFwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Forward- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Forward");
    lcd.setCursor(0, 1);
    lcd.print(tim);

    delay(50);
  }


}
void goBackward(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Backward");
  frontLeft.write(FLBwd);
  frontRight.write(FRBwd);
  backLeft.write(BLBwd);
  backRight.write(BRBwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Backward- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Backward");
    lcd.setCursor(0, 1);
    lcd.print(tim);
    delay(50);
  }
}
void goBackward(int dly, int spd) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Backward");
  int FLVal = map(spd, 0, 100, 1500, FLBwd);
  int FRVal = map(spd, 0, 100, 1500, FRBwd);
  int BLVal = map(spd, 0, 100, 1500, BLBwd);
  int BRVal = map(spd, 0, 100, 1500, BRBwd);
  frontLeft.write(FLVal);
  frontRight.write(FRVal);
  backLeft.write(BLVal);
  backRight.write(BRVal);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Backward- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Backward");
    lcd.setCursor(0, 1);
    lcd.print(tim);
    lcd.print(" ");
    lcd.print(spd);
    delay(50);
  }
}
void goRight(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Right");
  frontLeft.write(FLFwd);
  frontRight.write(FRBwd);
  backLeft.write(BLFwd);
  backRight.write(BRBwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Right- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Right");
    lcd.setCursor(0, 1);
    lcd.print(tim);

    delay(50);
  }
}

void goRight(int dly, int spd) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Right");
  int FLVal = map(spd, 0, 100, 1500, FLFwd);
  int FRVal = map(spd, 0, 100, 1500, FRBwd);
  int BLVal = map(spd, 0, 100, 1500, BLFwd);
  int BRVal = map(spd, 0, 100, 1500, BRBwd);
  frontLeft.write(FLVal);
  frontRight.write(FRVal);
  backLeft.write(BLVal);
  backRight.write(BRVal);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Right- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Right");
    lcd.setCursor(0, 1);
    lcd.print(tim);
    lcd.print(" ");
    lcd.print(spd);
    delay(50);
  }
}



void goLeft(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Left");
  frontLeft.write(FLBwd);
  frontRight.write(FRFwd);
  backLeft.write(BLBwd);
  backRight.write(BRFwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Left- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Left");
    lcd.setCursor(0, 1);
    lcd.print(tim);
    delay(50);
  }
}
void goLeft(int dly, int spd) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Going Left");
  int FLVal = map(spd, 0, 100, 1500, FLBwd);
  int FRVal = map(spd, 0, 100, 1500, FRFwd);
  int BLVal = map(spd, 0, 100, 1500, BLBwd);
  int BRVal = map(spd, 0, 100, 1500, BRFwd);
  frontLeft.write(FLVal);
  frontRight.write(FRVal);
  backLeft.write(BLVal);
  backRight.write(BRVal);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Left- ");
    Serial.println(tim);
    lcd.clear();
    lcd.print("Going Left");
    lcd.setCursor(0, 1);
    lcd.print(tim);
    lcd.print(" ");
    lcd.print(spd);
    delay(50);
  }
}


int getDistance(int tPin, int ePin) {
  long duration;
  int distance;
  digitalWrite(tPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(tPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(ePin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;  // Speed of sound wave divided by 2 (go and back)
  return distance;
}
