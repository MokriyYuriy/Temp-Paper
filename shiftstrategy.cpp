#include "strategy.h"

static std::vector <int> FindAllCows(Player *player, std::size_t n, std::size_t m) {
    std::vector <int> first_set, second_set;
    bool is_first_answer;
    if (n == m) {
        std::vector <int> answer(n);
        for (std::size_t i = 0; i < n; i++) {
            answer[i] = i;
        }
        return answer;
    }
    first_set.push_back(0);
    for (std::size_t i = 1; i < m; i++) {
        Response zero_query, i_query;
        std::size_t p = 0;
        std::vector <int> query_string(n);
        for (std::size_t j = 1; p != n - 1; j++) {
            if (j == i) continue;
            query_string[p++] = j;
        }
        query_string.back() = 0;
        zero_query = player->query(query_string);
        query_string.back() = i;
        i_query = player->query(query_string);
        if (zero_query.get_cows_and_bulls() == i_query.get_cows_and_bulls()) {
            first_set.push_back(i);
        } else {
            second_set.push_back(i);
            if (zero_query.get_cows_and_bulls() > i_query.get_cows_and_bulls()) {
                is_first_answer = true;
            } else {
                is_first_answer = false;
            }
        }
    }
    if (is_first_answer) return first_set;
    return second_set;
}

static std::vector <int> FindPermutation(Player *player, std::vector <int> string, std::size_t n, std::size_t m) {
    std::vector <int> answer(n);
    if (n == 1) return {0};
    for (std::size_t i = 0; i < n; i++, std::rotate(string.begin(), string.begin() + 1, string.end())) {
        bool is_first_answer;
        std::vector <int> first_set, second_set, bulls;
        Response zero_query = player->query(string);
        if (zero_query.get_bulls() == 0) continue;
        if (zero_query.get_bulls() == (int)n) return string;
        first_set.push_back(0);
        for (std::size_t j = 1; j < n; j++) {
            std::swap(string[0], string[j]);
            Response j_query = player->query(string); 
            std::swap(string[0], string[j]);
            if (j_query.get_bulls() >= zero_query.get_bulls()) {
                is_first_answer = false;
                first_set.push_back(j);
            } else if (j_query.get_bulls() + 1 == zero_query.get_bulls()) {
                second_set.push_back(j);
            } else {
                is_first_answer = true;
                first_set.push_back(j);
            }
        }
        bulls = (is_first_answer ? first_set : second_set);
        for (std::size_t j = 0; j < bulls.size(); j++) {
            answer[bulls[j]] = string[bulls[j]];
        }
    }
    return answer;
}

int SimpleShiftStrategy(Player *player, std::size_t n, std::size_t m) {
    std::vector <int> string = FindAllCows(player, n, m);
    string = FindPermutation(player, string, n, m);
    return player->get_score();
}
