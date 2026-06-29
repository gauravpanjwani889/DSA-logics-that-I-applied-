class Solution {
public:
    void dfs(int node, const vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        // Loop through the neighbors of the current node
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        
        // Corrected: A vector containing 'n' vectors
        vector<vector<int>> adj(n); 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    // adj[j].push_back(i); // Optional: if you check all i and j pairs, this duplicates edges, but won't break correctness.
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt++;
                dfs(i, adj, vis);
            }
        }

        return cnt;
    }
};