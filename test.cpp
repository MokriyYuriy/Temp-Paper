#include "player.h"
#include "oracul.h"
#include "strategy.h"
#include "test.h"
#include <iostream>

static const int TEST = 100, MAXN = 200, MAXM = 250;

Result::Result() {}

Result::Result(size_t n, size_t m, int score) : n(n), m(m), score(score) {}

std::vector <Result> TestStrategy(int (*strategy)(Player *, size_t, size_t)) {
    std::vector <Result> result;
    for (int test = 0; test < TEST; test++) {
        std::default_random_engine random(test * 31 + 79);
        int n = random() % MAXN + 1, m = random() % (MAXM - n) + n, seed = 42 * test * test + test * 179 + 57, score;
        RandomOracul oracul(n, m, seed);
        SimplePlayer player(&oracul);
        score = strategy(&player, n, m);
        result.push_back(Result(n, m, score));
        std::cout << player.is_end() << std::endl; 
    }
    return result;
}

int main() {
/*    std::vector <Result> result = TestStrategy(BruteForceStrategy);
    for (int i = 0; i < TEST; i++) {
        std::cout << result[i].n << ' ' << result[i].m << ' ' << result[i].score << std::endl;  
    } //*/
    std::vector <Result> result = TestStrategy(SimpleShiftStrategy);
    for (int i = 0; i < TEST; i++) {
        std::cout << result[i].n << ' ' << result[i].m << ' ' << result[i].score << std::endl;  
    }
    return 0;
}
