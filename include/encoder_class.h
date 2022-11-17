#include <Arduino.h>


class Encoder
{

private:

    uint8_t pinA;
    uint8_t pinB;

public: 

    int32_t last_state;
    int32_t position;

    Encoder(uint8_t input_pinA, uint8_t input_pinB);
    int32_t get_position (long last_state);
    
};
