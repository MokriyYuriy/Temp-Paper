#include <random>
#include <algorithm>
#include <vector>
#include <cassert>

#ifndef BASIC_CLASSES_H
#define BASIC_CLASSES_H

const int INF = (int)1e8;

class Response {
 private:
    int cows, bulls;
 public:
    Response();
    Response(int cows, int bulls);
    int get_cows() const;
    int get_bulls() const;
    int get_cows_and_bulls() const;
};

class Oracle {
 protected:
    std::size_t n, m;
    std::vector <int> secret_string;
 public:
    std::size_t get_n() const;
    std::size_t get_m() const;
    virtual Response query(const std::vector <int> &query_string) = 0;
};

class Player {
 protected:
    Oracle *oracle;
    int score;
    bool end;
 public:
    virtual Response query(const std::vector <int> &query_string) = 0;
    int get_score() const;
    bool is_end() const;
};

#endif
