#include "basic_classes.h"

#ifndef STRATEGY_H
#define STRATEGY_H

int BruteForceStrategy(Player *player, std::size_t n, std::size_t m);
int SimpleShiftStrategy(Player *player, std::size_t n, std::size_t m);
int AdvancedShiftStrategy(Player *player, std::size_t n, std::size_t m);
int ChoosePossibleStrategy(Player *player, std::size_t n, std::size_t m);
int LarmouthStrategy(Player *player, std::size_t n, std::size_t m);
int CrushStrategy(Player *player, std::size_t n, std::size_t m);

#endif
