#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj, int start)
{

    vector<bool> vis(adj.size(), false);
    queue<int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                q.push(it);
            }
        }
    }
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(adj, 0);
}