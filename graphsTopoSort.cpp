#include <bits/stdc++.h>
using namespace std;

// Class to represent the solution
class Solution {
private:
    vector<int> topologicalSort(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        return topo;
    }

public:
    // Function to find the order of characters in the alien dictionary
    string findOrder(string dict[], int N, int K) {
        vector<int> adj[K];
        
        for(int i=0; i<N-1; i++) {
            string s1 = dict[i];
            string s2 =  dict[i+1];

            int len = min(s1.size(), s2.size());
            int j=0;
            while(j<len && s1[j] == s2[j]) {
                j++;
            }

            if(j<len) {
            adj[s1[j] - 'a'].push_back(s2[j] - 'a');
            }
        }
        
        vector<int> topoSort = topologicalSort(K, adj);
        string ans = "";

        for(int i=0; i<K; i++) {
            ans += char('a' + topoSort[i]);
        }

        return ans;
    }
};

// Driver Code
int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    Solution obj;
    string ans = obj.findOrder(dict, N, K);

    // Print result
    for (auto ch : ans) {
        cout << ch << " ";
    }
    cout << endl;

    return 0;
}
