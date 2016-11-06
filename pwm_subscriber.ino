#include <ros.h>
#include <Servo.h>
#include "lib/msg/pwm_message.h"

#define CH1 5
#define CH2 4
#define CH3 3
#define CH4 27
#define CH5 26
#define CH6 25

Servo servo1, servo2, servo3, servo4, servo5, servo6;

ros::NodeHandle nh;

void messageCb( const s_rov_messages::pwm& pwm){
  servo1.write((180*pwm.pwm1)/255);
  servo2.write((180*pwm.pwm2)/255);
  servo3.write((180*pwm.pwm3)/255);
  servo4.write((180*pwm.pwm4)/255);
  servo5.write((180*pwm.pwm5)/255);
  servo6.write((180*pwm.pwm6)/255);
}

ros::Subscriber<s_rov_messages::pwm> sub("control/pwm", &messageCb );

void setup()
{
  servo1.attach(CH1); servo2.attach(CH2); servo3.attach(CH3);
  servo4.attach(CH4); servo5.attach(CH5); servo6.attach(CH6);

  servo1.write(0); servo2.write(0); servo3.write(0);
  servo4.write(0); servo5.write(0); servo6.write(0);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}

