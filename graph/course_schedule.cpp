#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& adj_list, vector<bool>& path, vector<bool>& vis, int start) {
        vis[start] = true;
        path[start] = true;

        for (int it : adj_list[start]) {
            if (!vis[it]) {
                vis[it] = true;
                if (dfs(adj_list, path, vis, it)) {
                    return true;
                }
            } else {
                if (path[it] == true) {
                    return true;
                }
            }
        }

        path[start] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj_list[v].push_back(u);
        }

        vector<bool> path(numCourses);
        vector<bool> vis(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                bool ans = dfs(adj_list, path, vis, i);
                if (ans == true)
                    return false;
            }
        }
        return true;
    }
};