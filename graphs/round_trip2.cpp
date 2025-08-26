#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int v, vector<bool> &visited, vector<vector<int>> &adj,
         map<int,int> &parent, int &start, vector<int> &path) {
    visited[v] = true;
    path[v] = 1; 

    for (auto it : adj[v]) {
        if (!visited[it]) {
            parent[it] = v;
            dfs(it, visited, adj, parent, start, path);
            if(start!=-1)
            {
                return;
            }
        } 
        else if (path[it]) {
            
            start = v;
            parent[it]=v;
            return;
        }
    }

    path[v] = 0; 
}

int32_t main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
    }

    vector<bool> visited(n, false);
    vector<int> path(n, 0);
    map<int,int> parent;
    int start = -1;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && start==-1) {
            dfs(i, visited, adj, parent, start, path);
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        // Reconstruct cycle
        vector<int> cycle;
        cycle.push_back(start);
        int v = parent[start];
        while (v != start) {
            cycle.push_back(v);
            v = parent[v];
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int v : cycle) cout << v+1 << " ";
        cout << endl;
    }
}
