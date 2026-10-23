#include <bits/stdc++.h>
using namespace std;

// Class to solve the Rat in a Maze problem
class Solution {
public:
    void findAllPaths(int i, int j, vector<string>& ans, vector<vector<int>>& vis, vector<vector<int>>& maze,
        int n, vector<int>& vi, vector<int>& vj, string temp){
            if(i==n-1 && j==n-1){
                ans.push_back(temp);
                return;
            }

            string dir = "DLRU";
            for(int ind=0;ind<4;ind++){
                int nexti = i + vi[ind];
                int nextj = j + vj[ind];
                if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && vis[nexti][nextj]==0 && maze[nexti][nextj]==1){
                    vis[i][j]=1;
                    findAllPaths(nexti,nextj,ans,vis,maze,n,vi,vj,temp+dir[ind]);
                    vis[i][j]=0;
                }
            }
        }

    // Main function to find all paths
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n,0));
        vector<int> vi = {1, 0, 0, -1};
        vector<int> vj = {0, -1, 1, 0};
        if(maze[0][0] == 1) findAllPaths(0,0,ans,vis,maze,n,vi,vj,"");
        return ans;
    }
};

// Driver code
int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    int n = maze.size();
    Solution obj;
    vector<string> paths = obj.findPath(maze, n);

    for (auto &p : paths) cout << p << " ";
}
