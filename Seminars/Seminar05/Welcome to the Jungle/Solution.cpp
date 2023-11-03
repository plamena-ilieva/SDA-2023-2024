#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> trees(n);
    
    for(int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    
    stack<int> s;
    int max = 1;
    int idx = n-1;
    for(int i = n-1; i >= 0; --i) {
        while(!s.empty() && a[i] >= s.top()) {
            s.pop();
        }        
        s.push(a[i]);
        if (max <= s.size()) {
            max = s.size();
            idx = i;
        }
    }
    cout<<idx<<endl;
}
