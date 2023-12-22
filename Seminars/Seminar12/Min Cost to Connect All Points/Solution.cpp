class DisjointSet{
public:
    vector<int> size, parent;

    DisjointSet(int n)
    {
        size.resize(n+1, 1);
        parent.resize(n+1);

        for(int i = 0; i<= n;i++)
        {
            parent[i] = i;
        }
    }

    int Find(int node)
    {
        if(node == parent[node]) return node;

        return parent[node] = Find(parent[node]);
    }

    bool Union(int u, int v)
    {
        int p_u = Find(u);
        int p_v = Find(v);

        if(p_u == p_v) return false;

        if(size[p_u] < size[p_v])
        {
            parent[p_u] = p_v;
            size[p_v] ++;
        }
        else
        {
            parent[p_v] = p_u;
            size[p_u] ++;
        }
        return true;
    }

};


#if 0
class Solution {
    // Using Kruskal
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        vector<array<int, 3>> adj;

        for(int i = 0; i<points.size(); i++)
        {
            for(int j = i+1; j<points.size(); j++)
            {
                int dist = abs(points[j][1] - points[i][1]) + abs(points[j][0] - points[i][0]);
                adj.push_back({i, j, dist});
            }
        }

        sort(adj.begin(), adj.end(), [](auto &a, auto &b){
            return a[2] < b[2];
        });

        int sum = 0;

        DisjointSet ds(points.size());

        for(int i = 0; i<adj.size(); i++)
        {
            int src = adj[i][0], dest = adj[i][1], wt = adj[i][2];

            if(ds.Union(src, dest))
            {
                sum += wt;
            }
        }

        return sum;

    }
};
#else
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        // using Prims

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> vis(points.size(), 0);

        pq.push({0,0});
        int sum = 0;

        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(!vis[node])
            {
                vis[node] = 1;
                sum += wt;
                for(int adjNode = 0; adjNode < points.size(); adjNode++)
                {
                    if(!vis[adjNode])
                    {
                        int dist = abs(points[adjNode][1] - points[node][1])
                        + abs(points[adjNode][0] - points[node][0]);

                        pq.push({dist, adjNode});
                    }
                }
            }
        }

        return sum;

    }
};
#endif