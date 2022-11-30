#include <Arduino.h>


class Encoder
{

private:

    uint8_t pinA;
    uint8_t pinB;
    uint16_t ppr;

public: 

    int32_t last;
    float position;
    int32_t ticks;

    Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t ppr);
    int32_t get_position (long last_state);
    
};
