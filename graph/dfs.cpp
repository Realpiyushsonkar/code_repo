#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj_list, vector<bool> &visited, int start) {
    visited[start] = true;

    for(int i : adj_list[start]) {
        if(!visited[i]) {
            dfs(adj_list, visited, i);
        }
    }
}