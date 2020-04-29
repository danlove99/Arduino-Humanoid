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

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);

}

void rightAttack()
{
  pass;
}

void leftAttack()
{
 pass;
}

void forward()
{
 pass;
}

void backward()
{
 pass;
}

int pulseWidth(int angle)
{
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}


void loop() {
  // head test
  pwm.setPWM(hd,0,pulseWidth(180);
  pwm.setPWM(hd,0,pulseWidth(20);
  // left shoulder test
  pwm.setPWM(ls,0,pulseWidth(180));
  pwm.setPWM(ls,0, pulseWidth(20));
  // left arm test
  pwm.setPWM(la,0,pulseWidth(180));
  pwm.setPWM(la,0, pulseWidth(20));
  // right shoulder test
  pwm.setPWM(rs,0,pulseWidth(180));
  pwm.setPWM(rs,0, pulseWidth(20));
  // right arm test
  pwm.setPWM(ra,0,pulseWidth(180)0);
  pwm.setPWM(ra,0, pulseWidth(20));
  // left leg test
  pwm.setPWM(ll,0,pulseWidth(180));
  pwm.setPWM(ll,0, pulseWidth(20));
  // left foot test
  pwm.setPWM(lf,0,pulseWidth(180));
  pwm.setPWM(lf,0, pulseWidth(20));
  // right leg test
  pwm.setPWM(rl,0, pulseWidth(180));
  pwm.setPWM(rl,0, pulseWidth(20));
  // right foot test
  pwm.setPWM(rf,0, pulseWidth(180));
  pwm.setPWM(rf,0, pulseWidth(20));
}
