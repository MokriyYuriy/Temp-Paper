#include "strategy.h"
#include "simpletools.h"
#include "equivalence.h"
#include "cmath"
#include <algorithm>

static bool cmp(const std::vector <int> &string, std::vector <int> a, std::vector <int> b,
                const std::vector <std::pair <std::vector <int>, Response>> &T,
                std::size_t n, std::size_t m) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (std::size_t i = 0; i < std::min(a.size(), b.size()); i++) {
        if (a[i] == b[i]) {
            continue;
        }
        return a[i] < b[i];
    }
    if (queries_satisfaction(string, T, n, m)) {
        return true;
    } 
    return false;
} 

int CrushStrategy(Player *player, std::size_t n, std::size_t m) {
    std::vector <std::pair<std::vector <int>, Response>> T;
    int score = 0;
    while (true) {
        score++;
        std::vector <std::vector <int>> classes;
        std::vector <int> best_string;
        classes = find_eq_classes(n, m, T);
        best_string = classes[0];
        std::vector <int> mnN = get_N(classes[0], T, n, m);
        for (std::size_t i = 1; i < classes.size(); i++) {
            std::vector <int> new_mnN  = get_N(classes[i], T, n, m);
            if (cmp(classes[i], new_mnN, mnN, T, n, m)) {
                mnN = new_mnN;
                best_string = classes[i];
            }
        }
        T.emplace_back(best_string, player->query(best_string));
        if (T.back().second.get_bulls() == (int)n) {
            break;
        }
        //std::cout << "YAY" << std::endl;
    }
    return score;
}
