#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Time {
    long beg;
    long end;
    Time() {}
    
    Time(long beg, long end) : beg(beg), end(end) {}
};

bool operator<(Time t1, Time t2) {
    if (t1.end == t2.end) {
        return t1.beg < t2.beg;
    }
    return t1.end > t2.end;
}

bool cmp(Time t1, Time t2) {
    return t1.beg < t2.beg;
}

int main() {
    long n;
    cin >> n;
    vector<Time> v(n);
    for (int i = 0; i < n; i++) {
        long b, e;
        cin >> b >> e;
        Time t(b,e);
        v[i] = t;
    }
    sort(v.begin(), v.end(), cmp);
    priority_queue<Time> q;
    unsigned long maxSize = 0;
    
    for(long i = 0; i < n; ++i) {
        Time t = v[i];
        if (t.beg == t.end) {
            continue;
        }
        q.push(t);
        
        while(!q.empty() && q.top().end <= t.beg) {
            q.pop();
        }
        
        if (maxSize < q.size()) {
            maxSize = q.size();
        }
    }
    
    printf("%ld", maxSize);
    return 0;
}
