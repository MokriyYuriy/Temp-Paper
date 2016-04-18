#include "strategy.h"

static bool BruteForce(Player *player, int n, int m, int ln,
                      std::vector <bool> &used, std::vector <int> &lst) {
    if (ln == n) {
        if((player->query(lst)).get_bulls() == n) {
            return true;
        }
        return false;
    }
    for (int i = 0; i < m; i++) {
        if (!used[i]) {
            used[i] = true;
            lst[ln] = i;
            if (BruteForce(player, n, m, ln + 1, score, used, lst)) {
                return true;
            }
            used[i] = false;
        }
    }
    return false;
}

int BruteForceStrategy(Player *player, std::size_t n, std::size_t m)  {
    std::vector <bool> used(m, false);
    std::vector <int> lst(n);
    BruteForce(player, n, m, 0, used, lst);
    return player.get_score();
}
