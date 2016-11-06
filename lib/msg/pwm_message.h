#ifndef _ROS_s_rov_messages_pwm_h
#define _ROS_s_rov_messages_pwm_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace s_rov_messages
{

  class pwm : public ros::Msg
  {
    public:
      uint8_t pwm1;
      uint8_t pwm2;
      uint8_t pwm3;
      uint8_t pwm4;
      uint8_t pwm5;
      uint8_t pwm6;

    pwm():
      pwm1(0),
      pwm2(0),
      pwm3(0),
      pwm4(0),
      pwm5(0),
      pwm6(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->pwm1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm1);
      *(outbuffer + offset + 0) = (this->pwm2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm2);
      *(outbuffer + offset + 0) = (this->pwm3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm3);
      *(outbuffer + offset + 0) = (this->pwm4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm4);
      *(outbuffer + offset + 0) = (this->pwm5 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm5);
      *(outbuffer + offset + 0) = (this->pwm6 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->pwm6);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->pwm1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm1);
      this->pwm2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm2);
      this->pwm3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm3);
      this->pwm4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm4);
      this->pwm5 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm5);
      this->pwm6 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->pwm6);
     return offset;
    }

    const char * getType(){ return "s_rov_messages/pwm"; };
    const char * getMD5(){ return "cc6aae0bb7a61eb958b1859507db5189"; };

  };

}
#endif