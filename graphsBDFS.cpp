#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
    bool dfsCheck (int node, vector<int> adj[], int vis[], int pathVis[]) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfsCheck(adjNode, adj, vis, pathVis)) {
                    return true;
                }
            } else if (pathVis[adjNode]) {
                return true;
            }
        }
        pathVis[node] = 0;

        return false;
    }

public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
		int vis[V] = {0};
        int pathVis[V] = {0};

        for (int i=0; i<V; i++) {
            if (!vis[i]) {
                if (dfsCheck(i, adj, vis, pathVis)) {
                    return true;
                }
            }
        }

        return false;
	}
};


int main() {

	// V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {2, 9}, {10}, {}};
	int V = 11;
	Solution obj;
	bool ans = obj.isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";

	return 0;
}
