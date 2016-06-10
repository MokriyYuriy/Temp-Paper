#include "player.h"
#include "oracle.h"
#include "strategy.h"
#include "test.h"
#include "optimal.h"
#include "tools.h"
#include <iostream>

static const int TEST = 5000, MAXN = 1000, MAXM = 1000;

Result::Result() {}

Result::Result(size_t n, size_t m, int score) : n(n), m(m), score(score) {}

std::vector <Result> TestStrategy(int (*strategy)(Player *, size_t, size_t)) {
    std::vector <Result> result;
    for (int test = 0; test < TEST; test++) {
        std::default_random_engine random(test * 31 + 79);
        random();
        int n = random() % MAXN + 1, m = random() % (MAXM + 1 - n) + n, seed = 42 * test * test + test * 179 + 57, score;
        RandomOracle oracle(n, m, seed);
        SimplePlayer player(&oracle);
        score = strategy(&player, n, m);
        if (!player.is_end()) { 
            std::cerr << "Test #" << test << ": The game wasn't finished\n";
            exit(0);
        }
        result.push_back(Result(n, m, score));
        //std::cout << test << ' ' << n << ' ' << m << ' ' << score << ' ' << player.is_end() << std::endl; 
    }
    return result;
}

std::vector <Result> ShiftTestStrategy(int (*strategy)(Player *, size_t, size_t)) {
    std::vector <Result> result;
    for (int test = 0; test < TEST; test++) {
        std::default_random_engine random(test * 31 + 79);
        random();
        int n = random() % MAXN + 1, m = random() % std::min(40, n / 2 + 1) + 2 * n, seed = 42 * test * test + test * 179 + 57, score;
        RandomOracle oracle(n, m, seed);
        SimplePlayer player(&oracle);
        score = strategy(&player, n, m);
        std::cerr << "Test #" << test << '\n';
        if (!player.is_end()) { 
            std::cerr << "Test #" << test << ": The game wasn't finished\n";
            exit(0);
        }
        result.push_back(Result(n, m, score));
        //std::cout << test << ' ' << n << ' ' << m << ' ' << score << ' ' << player.is_end() << std::endl; 
    }
    return result;
}


void TestOptimal(std::size_t n, std::size_t m) {
    std::vector <std::pair <std::vector <int>, Response>> T;
    std::vector <std::vector <int>> S = initial_S(n, m);
    AdditionalInfo info;
    info.trie.build(m);
    for (auto i = 0; i < S.size(); i++) {
        info.trie.insert(S[i]);
        if (i != info.trie.get_number(S[i])) {
            print_string(S[i]);
            std::cout << "Bad\n" << i << ' ' << info.trie.get_number(S[i]);
            exit(0);
        }
    }
    std::cout << sum_min_steps(T, S, n, m, initial_S(n, m), info).first << '\n';
}

int main() {
/*    std::vector <Result> result = TestStrategy(BruteForceStrategy);
    for (int i = 0; i < TEST; i++) {
        std::cout << result[i].n << ' ' << result[i].m << ' ' << result[i].score << std::endl;  
    } //*/

    TestOptimal(2, 2);
    return 0;
    
    std::vector <Result> result = ShiftTestStrategy(AdvancedShiftStrategy);
    std::cout << TEST << ' ' << MAXN << ' ' << MAXM << '\n';
    for (int i = 0; i < TEST; i++) {
        std::cout << result[i].n << ' ' << result[i].m << ' ' << result[i].score << std::endl;  
    }
    return 0;
}
