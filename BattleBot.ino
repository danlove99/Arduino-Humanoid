#include <Adafruit_PWMServoDriver.h>

#define hd 0 /* head */
#define ls 1 /* left shoulder */
#define la 2/* left arm */
#define rs 3 /* right shoulder */
#define ra 4/* right arm */
#define ll 5 /* left leg */
#define lf 6/* left foot */
#define rl 7 /* right leg */
#define rf 8/* right foot */

// Defenitions for PWM mapping

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(50);

}

void rightAttack()
{
 pwm.setPWM(ra, 0, pulseWidth(170));
 delay(200);
 pwm.setPWM(ra, 0, pulseWidth(70));
 delay(50);
 pwm.setPWM(ra, 0, pulseWidth(170));
 delay(200);
 pwm.setPWM(ra, 0, pulseWidth(70));
 delay(50);
 pwm.setPWM(ra, 0, pulseWidth(30));
 delay(100);

}

void leftAttack()
{
 pwm.setPWM(la, 0, pulseWidth(170));
 delay(200);
 pwm.setPWM(la, 0, pulseWidth(70));
 delay(50);
 pwm.setPWM(la, 0, pulseWidth(170));
 delay(200);
 pwm.setPWM(la, 0, pulseWidth(70));
 delay(50);
 pwm.setPWM(la, 0, pulseWidth(30));
 delay(100);
}

void shakeHead()
{
 pwm.setPWM(hd, 0, pulseWidth(80));
 delay(200);
 pwm.setPWM(hd, 0, pulseWidth(100));
 delay(200);
 pwm.setPWM(hd, 0, pulseWidth(80));
 delay(200);
 pwm.setPWM(hd, 0, pulseWidth(100));
 delay(200);
 pwm.setPWM(hd, 0, pulseWidth(90));
 delay(200);

}
void forward()
{
 pwm.setPWM(lf,0,pulseWidth(80));
 pwm.setPWM(rf,0,pulseWidth(80));
 delay(200);
 pwm.setPWM(ll,0,pulseWidth(110));
 pwm.setPWM(rl,0,pulseWidth(110));
 delay(200);
 pwm.setPWM(lf,0,pulseWidth(90));
 pwm.setPWM(rf,0,pulseWidth(90));
 delay(200);
 pwm.setPWM(lf,0,pulseWidth(100));
 pwm.setPWM(rf,0,pulseWidth(100));
 delay(200);
 pwm.setPWM(ll,0,pulseWidth(70));
 pwm.setPWM(rl,0,pulseWidth(70));
 delay(200);
 pwm.setPWM(lf,0,pulseWidth(90));
 pwm.setPWM(rf,0,pulseWidth(90));
 delay(200);
}

void backward()
{
 pwm.setPWM(lf,0,pulseWidth(80));
 pwm.setPWM(rf,0,pulseWidth(80));
 delay(200);
 pwm.setPWM(ll,0,pulseWidth(70));
 pwm.setPWM(rl,0,pulseWidth(70));
 delay(200);
 pwm.setPWM(lf,0,pulseWidth(90));
 pwm.setPWM(rf,0,pulseWidth(90));
 delay(200);
 pwm.setPWM(lf,0,pulseWidth(100));
 pwm.setPWM(rf,0,pulseWidth(100));
 delay(200);
 pwm.setPWM(ll,0,pulseWidth(110));
 pwm.setPWM(rl,0,pulseWidth(110));
 delay(200);
 pwm.setPWM(lf,0,pulseWidth(90));
 pwm.setPWM(rf,0,pulseWidth(90));
 delay(200);
}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}

void show()
{
 for (int i=0;i<5;i++){
   forward();
 }
 shakeHead();
 rightAttack();
 leftAttack();
 for (int i=0;i<5;i++){
   backward();
 }

}

void test()
{
 
  // head test
  pwm.setPWM(hd,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(hd,0,pulseWidth(20));
  delay(100);
  // left shoulder test
  pwm.setPWM(ls,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(ls,0, pulseWidth(20));
  delay(100);
  // left arm test
  pwm.setPWM(la,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(la,0, pulseWidth(20));
  delay(100);
  // right shoulder test
  pwm.setPWM(rs,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(rs,0, pulseWidth(20));
  delay(100);
  // right arm test
  pwm.setPWM(ra,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(ra,0, pulseWidth(20));
  delay(100);
  // left leg test
  pwm.setPWM(ll,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(ll,0, pulseWidth(20));
  delay(100);
  // left foot test
  pwm.setPWM(lf,0,pulseWidth(180));
  delay(100);
  pwm.setPWM(lf,0, pulseWidth(20));
  delay(100);
  // right leg test
  pwm.setPWM(rl,0, pulseWidth(180));
  delay(100);
  pwm.setPWM(rl,0, pulseWidth(20));
  delay(100);
  // right foot test
  pwm.setPWM(rf,0, pulseWidth(180));
  delay(100);
  pwm.setPWM(rf,0, pulseWidth(20));
  delay(100);
  Serial.print("Test complete!");
}

void loop() 
{
  test();
  show();
}
