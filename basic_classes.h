#include <random>
#include <algorithm>
#include <vector>
#include <cassert>

#ifndef BASIC_CLASSES_H
#define BASIC_CLASSES_H

class Response {
 private:
    int cows, bulls;
 public:
    Response();
    Response(int cows, int bulls);
    int get_cows();
    int get_bulls();
    int get_cows_and_bulls();
};

class Oracul {
 protected:
    std::size_t n, m;
    std::vector <int> secret_string;
 public:
    virtual Response query(const std::vector <int> &query_string) = 0;
};

class Player {
 protected:
    Oracul *oracul;
    int score;
    bool end;
 public:
    virtual Response query(const std::vector <int> &query_string) = 0;
    int get_score();
    bool is_end();
};

#endif
