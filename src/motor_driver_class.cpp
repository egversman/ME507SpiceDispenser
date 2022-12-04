#include <Arduino.h>
#include <motor_driver_class.h> 
       
Motor_driver :: Motor_driver ()
{

}

void Motor_driver :: initialize (uint8_t input_pinA, uint8_t input_pinB)
{
    pinA = input_pinA;
    pinB = input_pinB;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
}

void Motor_driver :: run_forwards (uint16_t input_speed)
{
    speed = input_speed; 
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
}

void Motor_driver :: run_backwards (uint16_t input_speed)
{
    speed = input_speed; 
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
}

void Motor_driver :: run_forwards_pwm (uint16_t input_speed)
{
    speed = input_speed; 
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
    vTaskDelay(speed);
    digitalWrite(pinA, LOW);
    vTaskDelay(speed);
}

void Motor_driver :: run_backwards_pwm (uint16_t input_speed)
{
    speed = input_speed; 
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    vTaskDelay(speed);
    digitalWrite(pinB, LOW);
    vTaskDelay(speed);

}