#include "strategy.h"
#include "simpletools.h"
#include "equivalence.h"
#include "cmath"
#include <iostream>

static double cost(const std::vector <int> &N, int ind) {
    double result = 0;
    for (std::size_t i = 0; i < N.size(); i++) {
        if (N[i] != 0) {
            result += (double)N[i] * log((double)N[i]);
        }
    }
    return result - 2.0 * log(2.0) * (double)ind;
} 

int LarmouthStrategy(Player *player, std::size_t n, std::size_t m) {
    std::vector <std::pair<std::vector <int>, Response>> T;
    int score = 0;
    while (true) {
        score++;
        std::vector <std::vector <int>> classes;
        std::vector <int> best_string;
        double mn;
        classes = find_eq_classes(n, m, T);
        best_string = classes[0];
        mn = cost(get_N(classes[0], T, n, m), queries_satisfaction(classes[0], T, n, m)); 
        for (std::size_t i = 1; i < classes.size(); i++) {
            double new_mn = cost(get_N(classes[i], T, n, m), queries_satisfaction(classes[i], T, n, m));
            if (new_mn < mn) {
                mn = new_mn;
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
