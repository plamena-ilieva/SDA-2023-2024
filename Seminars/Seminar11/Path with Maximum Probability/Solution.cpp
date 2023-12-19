class Solution {
public:
    using v = pair<double, int>;  // Define a pair type for probability and node index
    vector<vector<v>> adj;  // Adjacency list to store the graph

    void create_adj(int n, vector<vector<int>>& edges, vector<double>& succProb) {
        adj.resize(n);  // Resize the adjacency list to the number of nodes
        int eN = edges.size();
        for (int i = 0; i < eN; i++) {
            int v0 = edges[i][0], v1 = edges[i][1];  // Get the source and target nodes of the edge
            adj[v0].push_back({succProb[i], v1});  // Add the target node and its success probability to the adjacency list of the source node
            adj[v1].push_back({succProb[i], v0});  // Add the source node and its success probability to the adjacency list of the target node
        }
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<double> prob(n, 0);  // Initialize the probability vector for each node as 0
        create_adj(n, edges, succProb);  // Create the adjacency list for the graph
        priority_queue<v, vector<v>> pq;  // Priority queue to store nodes based on their probabilities in descending order

        pq.push({1.0, start});  // Push the start node with probability 1 to the priority queue
        prob[start] = 1.0;  // Set the probability of the start node as 1

        while (!pq.empty()) {
            auto [cur_prob, i] = pq.top();  // Get the node with the highest probability from the priority queue
            pq.pop();

            if (i == end) {  // If the current node is the end node, return its probability
                return cur_prob;
            }

            for (auto [next_prob, j] : adj[i]) {  // Iterate through the adjacent nodes of the current node
                double new_prob = cur_prob * next_prob;  // Calculate the new probability by multiplying the current probability with the success probability of the edge
                if (new_prob > prob[j]) {  // If the new probability is higher than the existing probability of the adjacent node
                    prob[j] = new_prob;  // Update the probability of the adjacent node
                    pq.push({new_prob, j});  // Push the adjacent node with its new probability to the priority queue for further exploration
                }
            }
        }
        return 0.0;  // If the end node is not reachable, return 0 as the maximum probability
    }
};
