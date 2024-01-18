#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, t, groups, n;
    cin >> k >> t >> groups >> n;
    priority_queue<int, vector<int>, greater<int>>q;

    for(int i = 1; i <= n; ++i) {
        int curr;
        cin >> curr;
        q.push(curr);

        if (i % t == 0 || i == n) {
            for(int j = 0; j < k; ++j) {
                printf("%d ", q.top());
                q.pop();
            }

            if (--groups == 0) {
                break;
            }
        }

    }

    int left = groups * k;
    for (int i = 0; i < left; ++i) {
        printf("%d ", q.top());
        q.pop();
    }

    return 0;
}
