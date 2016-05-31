#include "simpletools.h"
#include <iostream>

std::vector <int> next_string(const std::vector <int> &string, std::size_t n, std::size_t m) {
    std::vector <int> new_string = string;
    std::vector <bool> used(m, false);
    for (std::size_t i = 0; i < n; i++) {
        used[string[i]] = true;
    }
    int mx_empty = -1;
    for (int i = (int)m - 1; i >= 0; i--) {
        if (!used[i]) {
            mx_empty = i;
            break;
        }
    }
    int pref = -1;
    for (int i = (int)n - 1; i >= 0; i--) {
        if (mx_empty < string[i]) {
            mx_empty = string[i];
            used[string[i]] = false;
            continue;
        }
        pref = i;
        break;
    }
    if (pref != -1) {
        std::size_t pr = string[pref];
        for (std::size_t i = pr + 1; i < m; i++) {
            if (!used[i]) {
                used[pr] = false;
                used[i] = true;
                new_string[pref] = i;
                break;
            }
        }
    }
    for (int i = pref + 1, j = 0; i < (int)n && j < (int)m; j++) {
        if (!used[j]) {
            new_string[i++] = j;
        }
    }
    //print_string(new_string);
    return new_string;
}

bool query_satisfaction(const std::vector <int> &string,
                        const std::pair <std::vector <int>, Response> &query,
                        std::size_t n, std::size_t m) {
    std::vector <bool> used(m, false);
    int cows = 0, bulls = 0;
    for (std::size_t i = 0; i < n; i++) {
        used[query.first[i]] = true;
    }
    for (std::size_t i = 0; i < n; i++) {
        cows += used[string[i]];
        bulls += (string[i] == query.first[i]);
    }
    cows -= bulls;
    return cows == query.second.get_cows() && bulls == query.second.get_bulls();
}

bool queries_satisfaction(const std::vector <int> &string,
                          const std::vector <std::pair <std::vector <int>, Response>> &queries,
                          std::size_t n, std::size_t m) {
    for (std::size_t i = 0; i < queries.size(); i++) {
        if (!query_satisfaction(string, queries[i], n, m)) {
            return false;
        }
    }
    return true;
}

void print_string(const std::vector <int> &string) {
    for (std::size_t i = 0; i < string.size(); i++) {
        std::cout << string[i] << ' ';
    }
    std::cout << '\n';
}
