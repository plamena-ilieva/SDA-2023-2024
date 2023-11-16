#include <cstdio>
#include <iostream>
#include <set>

using namespace std;


int main() {
    int mapSize, count, shipSize;
    cin >> mapSize >> count >> shipSize;
    set<int> s;

    int shots;
    cin >> shots;
    int currentCount = (mapSize  + 1) / (shipSize + 1);

    for (int i = 1; i <= shots; i++) {
        int shot;
        cin >> shot;
        auto iterPair = s.insert(shot);
        if (!iterPair.second) {
            continue;
        }
        auto iter = iterPair.first;
        int left = 0;
        int right = mapSize+1;
        if (iter != s.begin()) {
            left = *(--iter);
            ++iter;
        }
        if (++iter != s.end()) {
            right = *iter;
        }
        int prevCount = (right - left) / (shipSize + 1);
        int leftCount = (shot - left) / (shipSize + 1);
        int rightCount = (right - shot) / (shipSize + 1);
        int diff = prevCount - (leftCount + rightCount);
        currentCount -= diff;

        if (currentCount < count) {
            printf("%d", i);
            return 0;
        }
    }
    printf("%d", -1);
    return 0;
}