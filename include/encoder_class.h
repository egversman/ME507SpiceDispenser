#include <Arduino.h>


class Encoder
{

private:

    uint8_t pinA;
    uint8_t pinB;
    uint16_t ppr;

public: 

    bool new_A;
    bool new_B;
    float position;
    int32_t ticks;

    Encoder(uint8_t input_pinA, uint8_t input_pinB, uint16_t input_ppr);


    float get_position (bool last_A, bool last_B);
    
};
