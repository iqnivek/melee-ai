#include <mml/ai.h>
#include <mml/moves.h>

RawInput _raw_shNeutralA[4] = {
  {X_BUTTON, 0, NO_FLAGS},
  {RELEASE, -1, JUMPSQUAT},
  {A_BUTTON, 11, JUMPSQUAT},
  {RELEASE, 0, JUMPSQUAT | SH_LENGTH}
};
Move _mv_shNeutralA = {.inputs = _raw_shNeutralA, .size = 4};

void waveshine(AI* player) {
  addMove(player, &_mv_downB);
  addMove(player, &_mv_shNeutralA);
}
