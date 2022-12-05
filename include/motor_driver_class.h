#include <Arduino.h>

class Motor_driver
{

private:

    uint8_t pinA;
    uint8_t pinB;
    uint8_t speed_pin;
    uint16_t speed;

public: 

        Motor_driver();

        void initialize (uint8_t pinA, uint8_t pinB);

        void run_forwards (uint16_t input_speed);

        void run_backwards (uint16_t input_speed);

        void run_forwards_pwm (uint16_t input_speed);

        void run_backwards_pwm (uint16_t input_speed);
    
      
};

 