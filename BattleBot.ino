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

void loop() {
  // head test
  pwm.setPWM(hd,0,320);
  pwm.setPWM(hd,0,200);
  // left shoulder test
  pwm.setPWM(ls,0,320);
  pwm.setPWM(ls,0,200);
  // left arm test
  pwm.setPWM(la,0,320);
  pwm.setPWM(la,0,200);
  // right shoulder test
  pwm.setPWM(rs,0,320);
  pwm.setPWM(rs,0,200);
  // right arm test
  pwm.setPWM(ra,0,320);
  pwm.setPWM(ra,0,200);
  // left leg test
  pwm.setPWM(ll,0,320);
  pwm.setPWM(ll,0,200);
  // left foot test
  pwm.setPWM(lf,0,320);
  pwm.setPWM(lf,0,200);
  // right leg test
  pwm.setPWM(rl,0,320);
  pwm.setPWM(rl,0,200);
  // right foot test
  pwm.setPWM(rf,0,320);
  pwm.setPWM(rf,0,200);
}
