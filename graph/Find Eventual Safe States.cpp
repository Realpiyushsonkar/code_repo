#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> kahn(vector<int> &indegree, vector<bool> &vis, vector<vector<int>> &adj_list, int V, vector<int> &result) {
        queue<int> q;
        int cnt = 0;
        
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            cnt++;
            result.push_back(curr);

            for(int i : adj_list[curr]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        
        return result;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> result;
        vector<int> indegree(n, 0);
        vector<bool> vis(n, false);

        vector<vector<int>> reverse_graph(n);

        for(int i = 0; i < n; i++) {
            for(int j : graph[i]) {
                reverse_graph[j].push_back(i); 
                indegree[i]++;                
            }
        }

        kahn(indegree, vis, reverse_graph, n, result);  
        sort(result.begin(), result.end());             
        return result;
    }
};