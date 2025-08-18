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
void dfs(int val,vector<vector<int>>&adj,set<int>&s1,vector<bool>&visited)
{
    if(visited[val])
    {
        return;
    }
    visited[val]=true;
    s1.insert(val);
    for(auto it:adj[val])
    {
       
        dfs(it,adj,s1,visited);
        
    }
    return;
}
int32_t main() {
   int n,m;
   cin>>n>>m;
   vector<vector<int>>edges;
   vector<vector<int>>adj(n);
   for(int i=0;i<m;i++)
   {
       int x,y,z;
       cin>>x>>y>>z;
       x--;
       y--;
       edges.push_back({x,y,z});
       adj[y].push_back(x);
   }
   set<int>s1;
   vector<bool>visited(n,false);
   dfs(n-1,adj,s1,visited);
   vector<int>ans(n,LLONG_MIN);
   ans[0]=0;
   bool found=false;
   for(int i=0;i<n;i++)
   {
       for(auto it:edges)
       {
           if(ans[it[0]]!=LLONG_MIN && ans[it[1]]<ans[it[0]]+it[2])
           {
               if(i==n-1 && s1.find(it[1])!=s1.end())
               {
                   found=true;
                   break;
               }
               ans[it[1]]=ans[it[0]]+it[2];
           }
           
       }
       if(found)
        {   
            break;
        }
   }
  if(ans[n-1]==LLONG_MIN || found)
  {
      cout<<-1<<endl;
  }
  else
  {
      cout<<ans[n-1]<<endl;
  }
    
   
}
