#include <ros.h>
#include <Servo.h>
#include "lib/msg/pwm_message.h"

#define MOTOR1 5
#define MOTOR2 4
#define MOTOR3 3
#define MOTOR4 27
#define CH5 26
#define LED 25

Servo motor_1, motor_2, motor_3, motor_4, ch_5, led;

ros::NodeHandle nh;

void messageCb( const s_rov_messages::pwm& pwm){
  motor_1.write((180*pwm.motor1)/255);
  motor_2.write((180*pwm.motor2)/255);
  motor_3.write((180*pwm.motor3)/255);
  motor_4.write((180*pwm.motor4)/255);
  ch_5.write((180*pwm.ch5)/255);
  led.write((180*pwm.led)/255);
}

ros::Subscriber<s_rov_messages::pwm> sub("control/pwm", &messageCb );

void setup()
{
  motor_1.attach(MOTOR1); motor_2.attach(MOTOR2);
  motor_3.attach(MOTOR3); motor_4.attach(MOTOR4);
  
  ch_5.attach(CH5);
  
  led.attach(LED, 0, 19000, 0, 180);
  
  motor_1.write(0); motor_2.write(0);
  motor_3.write(0); motor_4.write(0);
  ch_5.write(0)   ; led.write(0);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{
  nh.spinOnce();
  delay(1);
}

