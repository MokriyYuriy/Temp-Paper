#include "basic_classes.h"

#ifndef EQUIVALENCE_H
#define EQUIVALENCE_H


bool equivalence(const std::vector <int> &a, const std::vector <int> &b,
                 const std::vector <bool> &fixed_numbers);
std::vector <std::vector <int>> find_eq_classes(std::size_t n, std::size_t m,
                                             const std::vector <std::pair <std::vector <int>, Response>> T);

#endif
