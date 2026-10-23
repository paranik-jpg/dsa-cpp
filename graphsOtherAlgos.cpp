#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
        vis[node] = 1;
        for(auto adjNode : adj[node]) {
            if(!vis[adjNode]) {
                dfs(adjNode, vis, st, adj);
            }
        }
        st.push(node);
    }

    void revDFS(int node, vector<int>& vis, vector<int>& temp, vector<int> trans[]) {
        temp.push_back(node);
        vis[node] = 1;
        for(auto adjNode : trans[node]) {
            if(!vis[adjNode]) {
                revDFS(adjNode, vis, temp, trans);
            }
        }
    }

public:
    // Function to find the strongly connected components
    vector<vector<int>> kosaraju(int V, vector<int> adj[]) {

        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }

        vector<int> trans[V];

        for(int i = 0; i < V; i++) {
            vis[i] = 0;
            for(auto it : adj[i]) {
                trans[it].push_back(i);
            }
        }

        vector<vector<int>> ans;

        while(!st.empty()) {
            vector<int> temp;
            int node = st.top();
            st.pop();

            if(!vis[node]) {
                revDFS(node, vis, temp, trans);
                ans.push_back(temp);
            }
        }

        return ans;
    }
};

int main() {
    int n = 7;
    int edges[7][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {2, 4},
        {4, 3}, {3, 5},
        {5, 4}
    };

    vector<int> adj[n];
    for (int i = 0; i < 7; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    Solution obj;
    vector<vector<int>> ans = obj.kosaraju(n, adj);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
