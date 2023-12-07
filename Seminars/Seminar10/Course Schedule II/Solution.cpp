class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int& v = numCourses; // alias

        vector<vector<int>> adj(v);

        // building adjacency list
        for (auto& pr : prerequisites) {
            adj[pr[1]].emplace_back(pr[0]);
        }

        vector<bool> visited(v, false), pathVisited(v, false);
        vector<int> result;

        for (int node = 0; node < v; node++) {
            if (!visited[node] && dfs(adj, visited, pathVisited, result, node))
                return {};
        }

        reverse(result.begin(), result.end());
        return result;
    }

private:
    bool dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& pathVisited,
                vector<int>& result, int node)
    {
        if (pathVisited[node])
            return true;
        if (visited[node])
            return false;

        visited[node] = pathVisited[node] = true;

        for (auto& adjNode : adj[node]) {
            if (dfs(adj, visited, pathVisited, result, adjNode))
                return true;
        }

        pathVisited[node] = false;
        result.emplace_back(node);
        return false;
    }
};