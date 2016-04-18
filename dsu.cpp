#include "dsu.h"

DSU::DSU(std::size_t size) {
    rk.resize(size, 1);
    pr.resize(size);
    for (std::size_t i = 0; i < size; i++) {
        pr[i] = i;
    }
}

int DSU::get(int v) {
    if (v == pr[v]) return v;
    return pr[v] = get(pr[v]);
}

bool DSU::unite(int v, int u) {
    v = get(v);
    u = get(u);
    if (v == u) return false;
    if (rk[u] == rk[v]) rk[v]++;
    if (rk[u] > rk[v]) swap(v, u);
    pr[u] = v;
    return false;
}
