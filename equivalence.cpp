#include "equivalence.h"
#include "simpletools.h"

bool equivalence(const std::vector <int> &a, const std::vector <int> &b,
                 const std::vector <bool> &fixed_numbers) {
    std::size_t n = a.size();
    for (std::size_t i = 0; i < n; i++) {
        if (!(a[i] == b[i] || (!fixed_numbers[a[i]] && !fixed_numbers[b[i]]))) {
            return false;
        }
    }
    return true;
}

std::vector <std::vector <int>>
find_eq_classes(std::size_t n, std::size_t m,
                const std::vector <std::pair <std::vector <int>, Response>> T) {
    std::vector <bool> fixed_numbers(m, false);
    std::vector <int> string(n);
    std::vector <std::vector <int>> classes;
    for (std::size_t q = 0; q < T.size(); q++) {
        for (std::size_t i = 0; i < n; i++) {
            fixed_numbers[T[q].first[i]] = true;
        }
    }
    for (std::size_t i = 0; i < n; i++) {
        string[i] = i;
    }
    classes.push_back(string);
    string = next_string(string, n, m);
    while(check_is_first(string)) {
        bool new_class = true;
        for (std::size_t i = 0; i < classes.size(); i++) {
            if (equivalence(classes[i], string, fixed_numbers)) {
                new_class = false;
                break;
            }
        }
        if (new_class) {
            classes.push_back(string);
        }
        string = next_string(string, n, m);
    }
    return classes;
}

