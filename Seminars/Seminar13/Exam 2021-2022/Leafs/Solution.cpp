#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int weight[200000] = {};

int dfs(vector<vector<int>>& graph, int v, vector<bool>& visited) {
    visited[v] = true;

    for(auto curr: graph[v]) {
        if (!visited[curr]) {
            weight[v] += dfs(graph, curr, visited);
        }
    }
    return weight[v] + v;
}

int main() {
    int e, q;
    cin >> e >> q;
    int v = 200000;

    vector<vector<int>> graph(v+1);

    while(e--) {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
    }

    vector<bool> visited(v+1, false);
    for (int i = 1; i <= v; i++) {
        if(!visited[i]) {
            dfs(graph, i, visited);
        }
    }

    while(q--) {
        int x;
        cin >> x;
        cout << weight[x] << endl;
    }


    return 0;
}
