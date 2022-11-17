#ifndef _SHARES_H_
#define _SHARES_H_



#include "taskqueue.h"
#include "taskshare.h"


extern Queue<float> desired_weight;
extern Queue<float> desired_position;
extern Share<float> weight;
extern Share<float> position;


#endif // _SHARES_H_

