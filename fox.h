#ifndef FOX_H
#define FOX_H

#include <mml/ai.h>

typedef struct {
  u32 state;
} WaveshineInfo;

extern WaveshineInfo info;

void nair(AI* ai);
void shine(AI* ai);

#endif
