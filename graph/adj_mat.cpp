#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &adj_matrix, vector<bool> &visited, int start) {
    visited[start] = true;

    int n = adj_matrix.size();

    for(int v = 0; v < n; v++) {
        if(adj_matrix[start][v] == 1 && !visited[v]) {
            dfs(adj_matrix, visited, v);
        }
    }
}