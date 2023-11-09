#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Node {
    vector<size_t> children;
    size_t timeIn = 0;
    size_t timeOut = 0;
};

const size_t MAX_SIZE = 1e6 + 1;
Node tree[MAX_SIZE];
size_t timeCounter = 1;

void preOrder(size_t root) {
    tree[root].timeIn = timeCounter++;

    for (auto x: tree[root].children) {
        preOrder(x);
    }

    tree[root].timeOut = timeCounter++;
}

bool isPredecessor(size_t p, size_t ch) {
    return tree[p].timeIn < tree[ch].timeIn && tree[p].timeOut > tree[ch].timeOut;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N, parent, child;
    cin >> N;
    size_t ribs = N - 1;
    cin >> parent >> child;
    tree[parent].children.push_back(child);
    size_t root = parent;
    for (size_t i = 1; i < ribs; i++) {
        cin >> parent >> child;
        tree[parent].children.push_back(child);
    }

    preOrder(root);
    size_t Q, p, ch;
    cin >> Q;
    for (size_t i = 0; i < Q; ++i) {
        cin >> p >> ch;
        if (isPredecessor(p,ch)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}