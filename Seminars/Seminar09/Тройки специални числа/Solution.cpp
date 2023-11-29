#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    long long M, N;
    cin >> N >> M;
    unordered_map<long long, long long> l;
    unordered_map<long long, long long> r;
    vector<int> v(N);

    for (long long i = 0; i < N; ++i) {
        long long n;
        cin >> n;
        r[n]++;
        v[i] = n;
    }

    long long count = 0;
    for (long long i = 0; i < N; ++i) {
        r[v[i]]--;
        
        if (v[i] % M == 0) {
            count += l[v[i] / M] * r[v[i] * M];
        }
        
        l[v[i]]++;
    }


    printf("%lld", count);
    return 0;
}