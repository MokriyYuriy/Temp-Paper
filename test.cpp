#include "player.h"
#include "oracle.h"
#include "strategy.h"
#include "test.h"
#include <iostream>

static const int TEST = 1000, MAXN = 7, MAXM = 12;

Result::Result() {}

Result::Result(size_t n, size_t m, int score) : n(n), m(m), score(score) {}

std::vector <Result> TestStrategy(int (*strategy)(Player *, size_t, size_t)) {
    std::vector <Result> result;
    for (int test = 0; test < TEST; test++) {
        std::default_random_engine random(test * 31 + 79);
        int n = random() % MAXN + 1, m = random() % (MAXM - n) + n, seed = 42 * test * test + test * 179 + 57, score;
        RandomOracle oracle(n, m, seed);
        SimplePlayer player(&oracle);
        score = strategy(&player, n, m);
        if (!player.is_end()) {
            std::cerr << "The game wasn't finished\n";
            exit(0);
        }
        result.push_back(Result(n, m, score));
        std::cout << n << ' ' << m << ' ' << player.is_end() << std::endl; 
    }
    return result;
}

int main() {
/*    std::vector <Result> result = TestStrategy(BruteForceStrategy);
    for (int i = 0; i < TEST; i++) {
        std::cout << result[i].n << ' ' << result[i].m << ' ' << result[i].score << std::endl;  
    } //*/
    std::vector <Result> result = TestStrategy(ChoosePossibleStrategy);
    for (int i = 0; i < TEST; i++) {
        std::cout << result[i].n << ' ' << result[i].m << ' ' << result[i].score << std::endl;  
    }
    return 0;
}
