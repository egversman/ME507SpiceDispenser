#include <Arduino.h>
#include <motor_driver_class.h>

       
Motor_driver :: Motor_driver (uint8_t input_pinA, uint8_t input_pinB, uint8_t input_speed_pin)
{
    uint8_t pinA = input_pinA;
    uint8_t pinB= input_pinB;
    uint8_t speed_pin = input_speed_pin;
    uint16_t speed = 0;

    pinMode(pinA, OUTPUT);
    pinMode(pinB, OUTPUT);
    pinMode(speed_pin, OUTPUT);
}

void Motor_driver :: run_forwards (uint16_t input_speed)
{
    speed = input_speed; 
    analogWrite(speed_pin, speed);
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);
}

void Motor_driver :: run_backwards (uint16_t input_speed)
{
    speed = input_speed;
    analogWrite(speed_pin, speed);
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
}

void Motor_driver :: forward_ramp_up (void)
{
    digitalWrite(pinA, HIGH);
    digitalWrite(pinB, LOW);

    for(uint16_t i = 0; i < 255; i++)
    {
        analogWrite(pinA, i);
        vTaskDelay(15); 
    }
}

void Motor_driver :: forward_ramp_down (void)
    {
        digitalWrite(pinA, HIGH);
        digitalWrite(pinB, LOW);

        for(uint16_t i = 255; i >= 0; i--)
        {
            analogWrite(pinA, i);
            vTaskDelay(15); 
        }
    }

void Motor_driver :: backwards_ramp_up (void)
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);

    for(uint16_t i = 0; i < 255; i++)
    {
        analogWrite(pinB, i);
        vTaskDelay(15); 
    }
}

void Motor_driver :: backwards_ramp_down (void)
{
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);

    for(uint16_t i = 255; i >= 0; i--)
    {
        analogWrite(pinB, i);
        vTaskDelay(15); 
    }
}