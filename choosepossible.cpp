#include "strategy.h"
#include "simpletools.h"
#include <iostream>


int ChoosePossibleStrategy(Player *player, std::size_t n, std::size_t m) {
    static int test = 1;
    int score = 0;
    std::vector <int> string(n);
    std::vector <std::pair <std::vector <int>, Response>> queries;
    for (std::size_t i = 0; i < n; i++) {
        string[i] = i;
    }
    int i = 0;
    do {
        score++;
        i++;
        while (!queries_satisfaction(string, queries, n, m)) {
            string = next_string(string, n, m);
        }
        queries.emplace_back(string, player -> query(string));
        if (queries.back().second.get_bulls() == (int)n) {
            break;
        }
        //print_string(string);
        string = next_string(string, n, m);
    } while(true);
//    std::cout << test++ << '\n' ;
    return score;
}
