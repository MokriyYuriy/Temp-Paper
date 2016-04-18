#include "strategy.h"

static std::vector <int> FindAllCows(Player *player, std::size_t n, std::size_t m) {
    std::vector <int> answer(n), string(n);
    if (n == m) {
        for (std::size_t i = 0; i < n; i++) {
            answer[i] = i;
        }
        return answer;
    }
    for (std::size_t i = 1; i < m; i++) {
        
    }
}

int SimpleShiftStrategy(Player *player, std::size_t n, std::size_t m) {
    std::vector <int> string = FindAllCows(player, n, m);
    
}
