#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int main() {
    unordered_set<string> s;
    int n, m;
    cin >> n >> m;
    unordered_set<string> unique;
    cin.ignore();

    for(int i = 0; i < n; ++i) {
        char str[1000000];
        cin.getline(str, 1000000);
        string str1(str);
        if (s.find(str1) == s.end()) {
            unique.insert(str1);
            s.insert(str1);
        }
        else {
            unique.erase(str1);
        }
    }

    cout << unique.size();

    return 0;
}