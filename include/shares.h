#include <taskshare.h>         
#include <taskqueue.h>
#include <PrintStream.h>


extern Share<float> current_position;
extern Queue<float> current_weight;

extern Share<bool> door_open;

// Carosell Flags
extern Share<bool> inst_recieved;
extern Share<bool> correct_position;
extern Share<bool> zero;

