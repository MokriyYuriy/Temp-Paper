#include "basic_classes.h"
#include <random>

#ifndef ORACUL_H
#define ORACUL_H

class RandomOracul : public Oracul {
 protected:
    std::default_random_engine my_rand;
 public:
    RandomOracul(std::size_t _n, std::size_t _m, int rand_seed);
    Response query(const std::vector <int> &query_string);
};

#endif 
