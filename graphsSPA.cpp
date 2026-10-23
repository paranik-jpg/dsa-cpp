#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
        set<pair<int, int>> st;
        vector<int> dist(V, INT_MAX);

        st.insert({0, S});
        dist[S] = 0;

        while(!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for(auto itt : adj[node]) {
                int adjNode = itt[0];
                int wt = itt[1];

                if(dis + wt < dist[adjNode]) {
                    if(dist[adjNode] != INT_MAX) {
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + wt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};

int main()
{
    // Driver code.
    int V = 3, E = 3, S = 2;  // Number of vertices, edges, and source vertex
    vector<vector<int>> adj[V]; // Adjacency list representation of the graph

    // Example graph with edges and weights
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    Solution obj;
    // Call dijkstra function and store the result
    vector<int> res = obj.dijkstra(V, adj, S);

    // Output the shortest distance from source to all nodes
    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
