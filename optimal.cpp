#include "optimal.h"
#include <iostream>
#include "tools.h"

std::bitset <MAXLEN> build_bitset(const std::vector <std::vector <int>> &S, AdditionalInfo &info) {
    std::bitset <MAXLEN> bitS;
    for (auto string : S) {
        bitS.set(info.trie.get_number(string));
    }
    return bitS;
}

std::pair <int, std::vector <int>>
    sum_min_steps(std::vector <std::pair <std::vector <int>, Response>> &T,
                  std::vector <std::vector <int>> &S, std::size_t n, std::size_t m,
                  const std::vector <std::vector <int>> &initial_S,
                  AdditionalInfo &info) {

    if (S.size() == 0) {
        return {0, std::vector <int> ()};
    }
    if (S.size() == 1) {
        return {(T.empty() || T.back().second.get_bulls() != (int)n ? 1 : 0), S[0]};
    }
    
    
    int result = INF;
    std::vector <int> best_string;
    
    if (S.size() + 1 <= (n + 1) * (n + 2) / 2) {
        for (auto string : S) {
            std::vector <std::vector <std::vector <int>>> new_S = get_new_S(string, S, T, n, m);
            std::size_t mx = 0;
            for (std::size_t i = 0; i < new_S.size(); i++) {
                mx = std::max(mx, new_S[i].size());
            }
            if (mx < 2) {
                return {2 * S.size() - 1, string};
            }
        }
    }

    std::bitset <MAXLEN> bitS = build_bitset(S, info);
    
    if (T.size() < 10) {
        auto it = info.hash_map.find(bitS);
        if (it != info.hash_map.end()) {
            //std::cout << "OK" << std::endl;
            return it->second;
        }
    }

    std::vector <std::vector <int>> classes = (T.size() < 3) ? find_eq_classes(n, m, T) : initial_S;

    int t = 0;
    for (auto &string : classes) {
        std::vector <std::vector <std::vector <int>>> new_S = get_new_S(string, S, T, n, m);
        std::size_t p = 0;
        int new_result = 0;
        for (std::size_t i = 0; i <= n; i++) {
            for (std::size_t j = 0; i + j <= n; j++, p++) {
                if (T.size() == 0) {
                    std::cout << i << ' ' << j << ' ' <<t++ << std::endl; 
                }
                if (new_S[p].size() == S.size()) {
                    new_result = INF;
                    break;
                }
                if (new_result > result) {
                    break;
                }
                T.emplace_back(string, Response(i, j));
                new_result += sum_min_steps(T, new_S[p], n, m, initial_S, info).first;
                T.pop_back();
            }
        }
        if (new_result < result) {
            result = new_result;
            best_string = string;
        }
    }

    if(T.size() < 10) {
        info.hash_map[bitS] = {result + S.size(), best_string};
    }

    return {result + S.size(), best_string};
}
