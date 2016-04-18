#include "oracul.h"

RandomOracul::RandomOracul(std::size_t _n, std::size_t _m, int rand_seed) {
    n = _n, m = _m;
    my_rand = std::default_random_engine(rand_seed);
    for (size_t i = 0; i < m; i++) {
        secret_string.push_back(i);
    }
    std::shuffle(secret_string.begin(), secret_string.end(), my_rand);
    secret_string.resize(n);
}
