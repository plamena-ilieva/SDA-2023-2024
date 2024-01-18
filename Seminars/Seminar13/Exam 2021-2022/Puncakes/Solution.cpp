#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool OK(vector<size_t> &chefs, size_t time, size_t target) {
    size_t pancakes = 0;
    for (const auto &element: chefs) {
        pancakes += time / element;
        if (pancakes >= target) {
            return true;
        }
    }

    return false;
}

size_t binarySearch(vector<size_t> &chefs, size_t target) {
    size_t left = *(min_element(chefs.begin(), chefs.end()));
    size_t right = *(max_element(chefs.begin(), chefs.end()))*target;
    size_t res = 0;

    while (left <= right) {
        size_t mid = left + (right - left) / 2;
        if (OK(chefs, mid, target)) {
            right = mid - 1;
            res = mid;
        } else {
            left = mid + 1;
        }
    }
    return res;
}

int main() {
    size_t N, K;
    cin >> N >> K;
    vector<size_t> chefs(K);

    for (size_t i = 0; i < K; ++i) {
        cin >> chefs[i];
    }
    cout << binarySearch(chefs, N);
    return 0;
}