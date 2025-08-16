#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1000000007;
void printbinary(int num)
{
    for (int i = 10; i >= 0; i--)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;


    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}
int msb(int num)
{
    int pos = 0;
    while (num != 0)
    {
        pos++;
        num = num >> 1;
    }
    return pos;
}
void make_adj(vector<vector<int>>&v,vector<vector<int>>&adj)
{
    for(auto it:v)
    {
        adj[it[0]-1].push_back(it[1]-1);
        adj[it[1]-1].push_back(it[0]-1);
    }
}
void dfs(int val ,vector<bool>&visited,vector<vector<int>>&adj)
{
    if(visited[val])
    {
        return;
    }
    visited[val]=true;
    for(auto it:adj[val])
    {
            dfs(it,visited,adj);
   
    }
    return;
}
int32_t main() {
    // int t;
    // cin >> t;
    // while (t--) {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(m,vector<int>(2));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<2;j++)
            {
                int x;
                cin>>x;
                v[i][j]=x;
            }
        }
        vector<vector<int>>adj(n);
        make_adj(v,adj);
        vector<int>f;
        vector<bool>visited(n,false);
        for(int i=0;i<visited.size();i++)
        {
            if(!visited[i])
            {
                f.push_back(i);
                dfs(i,visited,adj);
            }
            
        }
        
        cout<<f.size()-1<<endl;
        if(f.size()>1)
        {
            for(int i=0;i<f.size()-1;i++)
            {
                cout<<f[i]+1<<" "<<f[i+1]+1<<endl;
            }
        }
        

    // }
}
