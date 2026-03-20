#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int start, vector<vector<int>> &isConnected, vector<bool> &visited) {

        visited[start] = true;

        int j = 0;
        for(int it : isConnected[start]) {

            if(it == 1 && !visited[j]) {
                dfs(j, isConnected, visited);
            }

            j++;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        vector<bool> visited(n, false);
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i, isConnected, visited);
                cnt++;
            }
        }

        return cnt;
    }
};