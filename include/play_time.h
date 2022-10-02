#ifndef GUARD_PLAY_TIME_H
#define GUARD_PLAY_TIME_H

#include "global.h"

#define PLAYTIME_RUNNING 1

void PlayTimeCounter_Reset(void);
void PlayTimeCounter_Start(void);
void PlayTimeCounter_Stop(void);
void PlayTimeCounter_Update(void);
void PlayTimeCounter_SetToMax(void);

extern u8 sPlayTimeCounterState;

#endif // GUARD_PLAY_TIME_H
