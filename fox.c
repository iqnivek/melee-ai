#include <mml/ai.h>
#include <mml/logic.h>
#include <mml/moves.h>
#include <mml/game_state.h>

#include "fox.h"
#include "cpuLogic.h"

RawInput _raw_shNeutralA[4] = {
  {X_BUTTON, 0, NO_FLAGS},
  {RELEASE, -1, JUMPSQUAT},
  {A_BUTTON, 11, JUMPSQUAT},
  {RELEASE, 0, JUMPSQUAT | SH_LENGTH}
};
Move _mv_shNeutralA = {.inputs = _raw_shNeutralA, .size = 4};

WaveshineInfo info = {0};

void addCleanUpLogic(AI* ai) {
  addLogic(ai, &resetOnWaitLogic);
}

void nair(AI* ai) {
  addMove(ai, &_mv_shNeutralA);
  info.state = 0;
}

void shine(AI* ai) {
  if (info.state == 0) {
    addMove(ai, &_mv_downB);
    info.state = 1;

    // TODO necessary?
    resetAfterFrameLogic.condition.arg1.u = CURRENT_FRAME + 30;
    addLogic(ai, &resetAfterFrameLogic);
  } else if (info.state == 1) {
    addLogic(ai, &nairLogic);
  }

  // TODO necessary?
  addCleanUpLogic(ai);
}
