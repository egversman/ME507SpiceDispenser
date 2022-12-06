/** @file motor_driver_class.cpp
 *  This is the source file for the motor driver class that is used to create the motor objects.
 * 
 *  @author    Grant Gabrielson
 *  @author    Bryce Turnipseed
 *  @author    John Bruner
 *  @author    Elijah Versman
 *  @date      2022-Dec 5
 *  @copyright 2022 by the authors 
 */

#include <Arduino.h>
#include <motor_driver_class.h> 
       
/** @brief Empty constructor for the class.
*/
Motor_driver :: Motor_driver ()
{

}

/** @brief   A function that initializes the motor driver object.
*   @param   input_pinA The first pin input for the given DC motor.
*   @param   input_pinB The second pin input for the given DC motor.
*/
void Motor_driver :: initialize (uint8_t input_pinA, uint8_t input_pinB)
{
    //sets pins
    pinA = input_pinA;
    pinB = input_pinB;

    //sets pin modes
    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}

/** @brief   A function that runs the motor forwards.
*   @param   input_speed Controls PWM.
*/
void Motor_driver :: run_forwards (uint16_t input_speed)
{
    //sets speed value
    speed = input_speed;

    //sets motor pins 
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
}

/** @brief   A function that runs the motor backwards.
*   @param   input_speed Controls PWM.
*/
void Motor_driver :: run_backwards (uint16_t input_speed)
{
    //sets speed value
    speed = input_speed; 

    //sets motor pins
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
}

/** @brief   A function that runs the motor forwards with PWM control.
*   @param   input_speed Controls PWM.
*/
void Motor_driver :: run_forwards_pwm (uint16_t input_speed)
{
    //sets speed value
    speed = input_speed; 

    //sets motor pins
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);

    //implements PWM control
    vTaskDelay(speed);
    digitalWrite(pinA, LOW);
    vTaskDelay(speed);
}

/** @brief   A function that runs the motor backwards with PWM control.
*   @param   input_speed Controls PWM.
*/
void Motor_driver :: run_backwards_pwm (uint16_t input_speed)
{
    //sets speed value
    speed = input_speed; 

    //sets motor pins
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);

    //implements PWM control
    vTaskDelay(speed);
    digitalWrite(pinB, LOW);
    vTaskDelay(speed);

}

/** @brief   A function that shuts the motor off.
*/
void Motor_driver :: stop_motor (void)
{
    //shuts off both motor pins
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, LOW);

}