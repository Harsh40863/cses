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
void back(map<int,int>&m,int val,vector<int>&ans)
{
    if(val==0)
    {
        ans.push_back(val+1);
        reverse(ans.begin(),ans.end());
        return;
    }
    ans.push_back(val+1);
    back(m,m[val],ans);
    return ;
    
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
        
        vector<bool>visited(n,false);
        queue<pair<int,int>>q;
        q.push({0,0});
        map<int,int>mu;
        for(int i=0;i<n;i++)
        {
            mu[i]=0;
        }
        mu[0]=-1;
        int lol=-1;
        visited[0]=true;
        while(!q.empty())
        {
            int val=q.front().second;
            int level=q.front().first;
            q.pop();
            if(val==n-1)
            {
                lol=level;
                break;
            }
            for(auto it:adj[val])
            {
                if(!visited[it])
                {
                    q.push({level+1,it});
                    visited[it]=true;
                    mu[it]=val;
                }
            }
        }
        if(lol==-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            
            vector<int>ans;
            back(mu,n-1,ans);
            cout<<ans.size()<<endl;
            for(int i=0;i<ans.size();i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }
        
        

    // }
}
