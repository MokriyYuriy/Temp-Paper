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

bool check_is_first(const std::vector <int> &string) {
    for (int i = 0; i < (int)string.size(); i++) {
        if (i != string[i]) {
            return true;
        }
    }
    return false;
}

std::vector <int> get_N(const std::vector <int> &query_string,
                        std::vector <std::pair <std::vector <int>, Response>> T,
                        std::size_t n, std::size_t m) {
    std::vector <std::vector <int>> possible_strings;
    std::vector <int> string(n);
    std::vector <int> N;
    for (std::size_t i = 0; i < n; i++) {
        string[i] = i;
    }
    do {
        if (queries_satisfaction(string, T, n, m)) {
            possible_strings.push_back(string);
        }
        string = next_string(string, n, m);
    } while(check_is_first(string));
    for (std::size_t i = 0; i < n; i++) {
        for (std::size_t j = 0; i + j < n; j++) {
            N.push_back(0);
            std::pair <std::vector <int>, Response> query = {query_string, Response(i, j)}; 
            for (std::size_t z = 0; z < possible_strings.size(); z++) {
                if (query_satisfaction(possible_strings[z], query, n, m)) {
                    N.back()++;
                }
            }
        }
    }
    return N;
}
