/** @file motor_driver_class.h
 *  This is the header file for the motor driver class which is used to create the motor driver objects.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <Arduino.h>

/** @brief Class for the motor driver.
 */

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

        void stop_motor(void);
    
      
};

 