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

struct Pair {
    size_t id;
    size_t time;
};

using namespace std;

int main() {
    size_t time, T, N, id;
    cin >> N;

    //contains the input information
    vector<Pair> input;

    //containes the times, ordered, so that we search fast for the closest smaller time
    set<size_t> times;

    //contains the most sold index for each time
    unordered_map<size_t, int> mostSold;

    //counts the times a product is sold
    unordered_map<int, size_t> counter;

    size_t maxTime = 0;
    for (size_t i = 0; i < N; ++i) {
        cin >> id >> time;
        input.push_back({id, time});
        times.insert(time);
        maxTime = max(time, maxTime);
    }

    long long maxPair = 0;
    long long maxId = -1;
    for (size_t i = 0; i < N; ++i) {
        size_t currentId = input[i].id;
        counter[currentId]++;
        if (counter[currentId] >= maxPair) {
            maxPair = counter[currentId];
            maxId = currentId;
        }
        mostSold[input[i].time] = maxId;
    }

    cin >> T;
    for (size_t i = 0; i < T; ++i) {
        cin >> time;
        if (time >= maxTime) {
            cout << mostSold[maxTime] << '\n';
            continue;
        }
        auto tempTime = times.lower_bound(time);
        if (time < *tempTime) {
            if (tempTime == times.begin()) {
                cout << -1 << '\n';
                continue;
            }
            time = *(--tempTime);
        } else {
            time = *tempTime;
        }

        cout << mostSold[time] << '\n';
    }
    return 0;
}