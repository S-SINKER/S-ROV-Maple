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
      uint8_t motor1;
      uint8_t motor2;
      uint8_t motor3;
      uint8_t motor4;
      uint8_t ch5;
      uint8_t led;

    pwm():
      motor1(0),
      motor2(0),
      motor3(0),
      motor4(0),
      ch5(0),
      led(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->motor1 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor1);
      *(outbuffer + offset + 0) = (this->motor2 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor2);
      *(outbuffer + offset + 0) = (this->motor3 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor3);
      *(outbuffer + offset + 0) = (this->motor4 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->motor4);
      *(outbuffer + offset + 0) = (this->ch5 >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ch5);
      *(outbuffer + offset + 0) = (this->led >> (8 * 0)) & 0xFF;
      offset += sizeof(this->led);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      this->motor1 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor1);
      this->motor2 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor2);
      this->motor3 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor3);
      this->motor4 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->motor4);
      this->ch5 =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->ch5);
      this->led =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->led);
     return offset;
    }

    const char * getType(){ return "s_rov_messages/pwm"; };
    const char * getMD5(){ return "01039a4a93018787bb989e33864960ad"; };

  };

}
#endif