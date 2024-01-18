#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    size_t N, M;
    cin >> N >> M;
    vector<long long> v1(N);
    vector<long long> v2(M);

    for (size_t i = 0; i < N; ++i) {
        cin >> v1[i];
    }
    for (size_t i = 0; i < M; ++i) {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    for (size_t i = 0; i < N; ++i) {
        auto iter = lower_bound(v1.begin(), v1.end(), v2[i]);
        cout << (iter - v1.begin()) << ' ';
    }

}
