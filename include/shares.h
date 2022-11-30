#ifndef _SHARES_H_
#define _SHARES_H_



#include "taskqueue.h"
#include "taskshare.h"


extern Queue<float> user_weight;
extern Queue<float> user_position;
extern Share<float> weight;
extern Share<float> position;
extern Queue<bool> spin_direction; 
extern Queue<String> current_state; 


#endif // _SHARES_H_

