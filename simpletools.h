#include "basic_classes.h"

#ifndef SIMPLETOOLS_H
#define SIMPLETOOLS_H

std::vector <int> next_string(const std::vector <int> &string, std::size_t n, std::size_t m);

bool queries_satisfaction(const std::vector <int> &string,
                          const std::vector <std::pair <std::vector <int>, Response>> &queries,
                          std::size_t n, std::size_t m);

bool query_satisfaction(const std::vector <int> &string,
                        const std::pair <std::vector <int>, Response> &query,
                        std::size_t n, std::size_t m);

void print_string(const std::vector <int> &string);

bool check_is_first(const std::vector <int> &string);

std::vector <int> get_N(const std::vector <int> &string,
                        std::vector <std::pair <std::vector <int>, Response>> T,
                        std::size_t n, std::size_t m); 

#endif
