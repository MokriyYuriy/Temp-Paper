#include "strategy.h"
#include "equivalence.h"
#include "simpletools.h"
#include "tools.h"

std::pair <int, std::vector <int>> sum_min_steps(std::vector <std::pair <std::vector <int>, Response>> &T,
                                                 std::vector <std::vector <int>> &S, std::size_t n, std::size_t m,
                                                 const std::vector <std::vector <int>> &intial_S, AdditionalInfo &info);
