#include "oracul.h"
#include <unordered_map>

Response RandomOracul::query(const std::vector <int> &query_string) {
    std::unordered_map <int, std::size_t> map;
    int cows, bulls;
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
