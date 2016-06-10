#include "basic_classes.h"
#include <unordered_map>
#include <bitset>
#include <vector>

#ifndef TOOLS_H
#define TOOLS_H

const int MAXLEN = 250;

struct Node {
    std::vector <Node *> lst;
    int cnt;
    Node(int size);
};

struct Trie {
    int size;
    Node *root;
    Trie();
    Trie(int _size);
    void build(int _size);
    ~Trie();
    void insert(const std::vector <int> &string);
    int get_number(const std::vector <int> &string);
};


struct AdditionalInfo {
    Trie trie;
    std::unordered_map <std::bitset <MAXLEN>, std::pair <int, std::vector <int>>> hash_map;
};

#endif
