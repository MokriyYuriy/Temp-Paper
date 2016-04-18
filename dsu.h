#include "basic_classes.h"

#ifndef DSU_H
#define DSU_H

class DSU {
 private:
    std::vector <int> pr, rk; 
 public:
    DSU(std::size_t size);
    int get(int v);
    bool unite(int v, int u);
};

#endif
