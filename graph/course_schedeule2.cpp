#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> kahn(vector<int> &indegree, vector<bool> &vis, vector<vector<int>> &adj_list, int V, vector<int> &result) {
        queue<int> q;
        int cnt = 0;
        
        for(int i = 0; i < indegree.size(); i++) {
            if(indegree[i] == 0) q.push(i);
            // result.push_back(i);
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;
            result.push_back(curr);
            for(int i : adj_list[curr]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
                // result.push_back(i);
            }
        }
        
        if(cnt != V) return {};
        return result;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj_list(numCourses);
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj_list[v].push_back(u);
        }

        vector<int> indegree(numCourses, 0);
        vector<bool> vis(numCourses, false);

        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            indegree[u]++;
        }

        vector<int> result;
        

        return kahn(indegree, vis, adj_list, numCourses, result);

    }
};