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


  /*int dist = getDistance(trigPin, echoPin);
    int dist = 0;
    Serial.print("Distance: ");
    Serial.print(dist);
    Serial.println(" cm");
    lcd.clear();
    lcd.setCursor(0, 0);
    count++;
    lcd.print(count);
    lcd.setCursor(0, 1);
    lcd.print(dist);
    delay(100);
  */




  //  for (int i = 10; i > 0; i--) {
  //    lcd.clear();
  //    lcd.setCursor(0, 0);
  //    //    lcd.print("Count down");
  //    lcd.print(i);
  //    delay(250);
  //  }
  //  lcd.clear();
  //  lcd.setCursor(0,0);
  //  lcd.print("BOOOOOOOM");
  //  delay(1500);



  if (Serial.available())
  {
    int x = Serial.parseInt();

    /*
        if (x != 0) {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("x = ");
          lcd.print(x);
          Serial.print("x = ");
          Serial.println(x);
          frontLeft.writeMicroseconds(x);
          frontRight.writeMicroseconds(x);
          backLeft.writeMicroseconds(x);
          backRight.writeMicroseconds(x);


        }

      }

    */




    if (x == 7) {
      for (int i = 0; i < 5; i++) {
        //          pwm.writeMicroseconds(serFL, 1800);
        //          pwm.writeMicroseconds(serFR, 900);
        //          pwm.writeMicroseconds(serBL, 1800);
        //          pwm.writeMicroseconds(serBR, 900);
        //          delay(250);
        //          pwm.writeMicroseconds(serFL, 900);
        //          pwm.writeMicroseconds(serFR, 1800);
        //          pwm.writeMicroseconds(serBL, 900);
        //          pwm.writeMicroseconds(serBR, 1800);
        //          delay(250);
      }
    }
    else if (x == 5) {
      Serial.println("forward");
      //      frontLeft.write(0)
      goForward(500);
      //      delay(500);
      //        goForwardMax(500);
      //        pwm.writeMicroseconds(serFL, 1800);
      //        pwm.writeMicroseconds(serFR, 900);
      //        pwm.writeMicroseconds(serBL, 1800);
      //        pwm.writeMicroseconds(serBR, 900);
      //        delay(500);

    }
    else if (x == 2) {
      Serial.println("backward");
      //      frontLeft.write(90);
      goBackward(500);
      //      delay(500);
      //        goBackwardMax(500);
      //        pwm.writeMicroseconds(serFL, 900);
      //
      //        pwm.writeMicroseconds(serFR, 1800);
      //        pwm.writeMicroseconds(serBL, 900);
      //        pwm.writeMicroseconds(serBR, 1800);
      //        delay(500);
    }
    else if (x == 1) {
      Serial.println("left");
      goLeft(250);
      //      delay(500);
      //        FL Fwd, BL Fwd FR bwd BR bwd
      //        pwm.writeMicroseconds(serFL, leftFwd);
      //        pwm.writeMicroseconds(serFR, rightBwd);
      //        pwm.writeMicroseconds(serBL, leftFwd);
      //        pwm.writeMicroseconds(serBR, rightBwd);
      //        delay(500);
      //        goRightMax(500);
    }
    else if (x == 3) {
      Serial.println("right");
      goRight(250);
      //        pwm.writeMicroseconds(serFL, leftBwd);
      //        pwm.writeMicroseconds(serFR, rightFwd);
      //        pwm.writeMicroseconds(serBL, leftBwd);
      //        pwm.writeMicroseconds(serBR, rightFwd);
      //        delay(500);
      //        goLeftMax(500);
    }

  }

  stopMoving();



}

void stopMoving() {
  frontLeft.write(1500);
  frontRight.write(1500);
  backLeft.write(1500);
  backRight.write(1500);
}
void goForward(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Forward");
  frontLeft.write(FLFwd);
  frontRight.write(FRFwd);
  backLeft.write(BLFwd);
  backRight.write(BRFwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Forward- ");
    Serial.println(tim);
    delay(50);
  }


}
void goBackward(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Backward");
  frontLeft.write(FLBwd);
  frontRight.write(FRBwd);
  backLeft.write(BLBwd);
  backRight.write(BRBwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Backward- ");
    Serial.println(tim);
    delay(50);
  }
}
void goRight(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Right");
  frontLeft.write(FLFwd);
  frontRight.write(FRBwd);
  backLeft.write(BLFwd);
  backRight.write(BRBwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Right- ");
    Serial.println(tim);
    delay(50);
  }
}
void goLeft(int dly) {
  long t = millis();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Going Left");
  frontLeft.write(FLBwd);
  frontRight.write(FRFwd);
  backLeft.write(BLBwd);
  backRight.write(BRFwd);
  while (millis() - t < dly) {
    long tim =  millis() - t;
    Serial.print("Going Left- ");
    Serial.println(tim);
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
