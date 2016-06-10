#include "tools.h"
#include "simpletools.h"
#include <iostream>

Node::Node(int size) {
    lst = std::vector <Node *> (size, NULL);
    cnt = 0;
}

Trie::Trie(int _size) {
    size = _size;
    root = new Node(size);
}

Trie::Trie() {root = NULL;}

static void clean_Trie(Node *root) {
    if (root == NULL) return;
    for (auto to : root->lst) {
        clean_Trie(to);
    }
    delete root;
}

Trie::~Trie() {
    clean_Trie(root);
}

void Trie::build(int _size) {
    root = new Node(_size);
    size = _size;
}

void Trie::insert(const std::vector <int> &string) {
    Node *now = root;
    for (int num : string) {
        now->cnt++;
        if (!now->lst[num]) {
            now->lst[num] = new Node(size);
        }
        now = now->lst[num];
    }
    now->cnt++;
}

int Trie::get_number(const std::vector <int> &string) {
    int result = 0;
    Node *now = root;
    for (int num : string) {
        for (int i = 0; i < num; i++) {
            result += (now->lst[i]) ? now->lst[i]->cnt : 0;
        }
        now = now->lst[num];
    }
    if (result >= MAXLEN) {
        std::cout << result << '\n';
        print_string(string);
        exit(0);
    }
    return result;
}

