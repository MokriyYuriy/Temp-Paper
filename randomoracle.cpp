#include "oracle.h"
#include <unordered_map>

RandomOracle::RandomOracle(std::size_t _n, std::size_t _m, int rand_seed) {
    n = _n, m = _m;
    my_rand = std::default_random_engine(rand_seed);
    for (size_t i = 0; i < m; i++) {
        secret_string.push_back(i);
    }
    std::shuffle(secret_string.begin(), secret_string.end(), my_rand);
    secret_string.resize(n);
}

Response RandomOracle::query(const std::vector <int> &query_string) {
    std::unordered_map <int, std::size_t> map;
    int cows = 0, bulls = 0;
    for (std::size_t i = 0; i < query_string.size(); i++) {
        map[query_string[i]] = i;
    }
    for (std::size_t i = 0; i < secret_string.size(); i++) {
        if (map.count(secret_string[i])) {
            if (map[secret_string[i]] == i) {
                bulls++;
            } else {
                cows++;
            }
        }
    }
    return Response(cows, bulls);
}
