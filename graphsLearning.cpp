#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void recDFS(int node, vector<int> adj[], int vis[], vector<int>& ans) {
        vis[node] = 1;
        ans.push_back(node);

        for(auto it : adj[node]) {
            if(!vis[it]) {
                recDFS(it, adj, vis, ans);
            }
        }
    }

public:
    // Function to perform DFS traversal
    vector<int> dfs(int v, vector<int> adj[]) {
        int vis[v] = {0};
        int start = 0;
        vector<int> ans;
        recDFS(start, adj, vis, ans);
        return ans;
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // Adjacency list
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {2};

    // Create object
    Solution sol;

    // Run DFS from node 0
    vector<int> result = sol.dfs(V, adj);

    // Print traversal
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}
