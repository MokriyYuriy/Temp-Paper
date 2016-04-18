#include "basic_classes.h"

#ifndef STRATEGY_H
#define STRATEGY_H

int BruteForceStrategy(Player *player, std::size_t n, std::size_t m);
int SimpleShiftStrategy(Player *player, std::size_t n, std::size_t m);
int AdvancedShiftStrategy(Player *Player, std::size_t n, std::size_t m);

#endif
