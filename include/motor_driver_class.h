#include <Arduino.h>


class Motor_driver
{

private:

    uint8_t pinA;
    uint8_t pinB;
    uint8_t speed_pin;
    uint16_t speed;

public: 

        Motor_driver(uint8_t pinA, uint8_t pinB, uint8_t speed_pin);

        void run_forwards (uint16_t input_speed);

        void run_backwards (uint16_t input_speed);
     
        void forward_ramp_up(void);
      
        void forward_ramp_down(void);

        void backwards_ramp_up(void);

        void backwards_ramp_down(void);
      
};

 