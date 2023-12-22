class DisjointSet {
    int par[101], size[101];
public:
    DisjointSet() {
        for(int i = 0; i < 101; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int Find(int u) {
        if(u == par[u]) return u;
        return par[u] = Find(par[u]);
    }

    void Union(int u, int v) {
        int p_u = Find(u);
        int p_v = Find(v);
        if(p_u == p_v) return;
        if(size[p_u] < size[p_v]) swap(p_u, p_v);
        par[p_v] = p_u;
        size[p_u] += size[p_v];
    }
};

class Solution {
    vector<pair<int, int>> E;           // {weight, index} -> index in edges of two nodes
    bool critical[201], non_critical[201];
    int m;

    int mst_skip(vector<vector<int>>& edges, int skip, int n) {
        E.clear();
        int count = 0;
        for(int i = 0; i < m; i++) {
            if(i == skip) continue;
            vector<int> &e = edges[i];
            E.push_back({e[2], i});
        }
        sort(E.begin(), E.end());
        struct DisjointSet dsu;
        int total = 0;
        for(int i = 0; i < E.size(); i++) {
            int ind = E[i].second;
            int w = E[i].first, u = edges[ind][0], v = edges[ind][1];

            if(dsu.Find(u) == dsu.Find(v)) continue;
            total += w;
            dsu.Union(u, v);
            count++;
        }

        // if edge "skip" happens to be a bridge, then the graph will get disconnected and MST cannot be formed(or formed with infinite weight)
        if(count != n - 1) return 1e9;

        return total;
    }

    int mst_include(vector<vector<int>>& edges, int include, int n) {
        E.clear();
        struct DisjointSet dsu;
        int total = 0;
        for(int i = 0; i < m; i++) {
            vector<int> &e = edges[i];
            if(i == include) {
                int w = e[2], u = e[0], v = e[1];
                dsu.Union(u, v);
                total += w;
                continue;
            }
            E.push_back({e[2], i});
        }
        sort(E.begin(), E.end());
        for(int i = 0; i < E.size(); i++) {
            int ind = E[i].second;
            int w = E[i].first, u = edges[ind][0], v = edges[ind][1];

            if(dsu.Find(u) == dsu.Find(v)) continue;
            total += w;
            dsu.Union(u, v);
        }

        return total;
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // critical edges are those, which if removed from the graph and MST is then constructed, the weight of MST would be more than the original MST weight.

        vector<vector<int>>ans(2);
        m = edges.size();
        int original_weight = mst_skip(edges, -1, n);

        // brute force for all edges to find if it is critical or not
        // TC = O(m * m log n)
        // try to remove an edge from graph and construct MST, if weight is increased then it is critical edge.
        for(int i = 0; i < m; i++) {
            int weight = mst_skip(edges, i, n);
            if(weight > original_weight) {
                // i is critical edge
                ans[0].push_back(i);
                critical[i] = 1;
            }
        }

        // brute force for all edges to find if it is non-critical or not
        // TC = O(m * m log n)
        // If by forcefully including edge i, we get higher weight than original, then it must be non-critical edge(one which is not in any MST). Because critical edges must be in MST, and for pseudo-critical, by forcefully including edge, we can still build an MST of same weight as original.
        for(int i = 0; i < m; i++) {
            int weight = mst_include(edges, i, n);
            if(weight > original_weight) {
                // i is non-critical
                non_critical[i] = 1;
            }
        }

        for(int i = 0; i < m; i++) {
            if(!critical[i] && !non_critical[i]) ans[1].push_back(i);
        }

        return ans;
    }

};