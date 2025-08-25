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

int32_t main() {
  int n,m;
  cin>>n>>m;
  vector<vector<int>>edges;
  for(int i=0;i<m;i++)
  {
      int x,y,z;
      cin>>x>>y>>z;
      edges.push_back({x-1,y-1,z});
  }
  vector<int>ans(n,0);
  ans[0]=0;
  vector<int>mm(n,-1);
  int start=-1;
  bool found=false;
  
  for(int i=0;i<n;i++)
  {
      for(auto edge:edges)
      {
          int u=edge[0];
          int v=edge[1];
          int dist=edge[2];
          if(ans[u]!=LLONG_MAX && ans[v]>ans[u]+dist)
          {
              ans[v]=ans[u]+dist;
              mm[v]=u;
              if(i==n-1)
              {
                  start=v;
                  found=true;
                  
              }
              
          }
          
      }
      if(found)
        {
            break;
        }
  }
  if(start!=-1)
  {
      cout<<"YES"<<endl;
      
      for(int i=0;i<n;i++)
      {
          start=mm[start];
      }
      int v=start;
      vector<int>cycle;
      cycle.push_back(v);
      v=mm[v];
      while(v!=start)
      {
          cycle.push_back(v);
          v=mm[v];
      }
      cycle.push_back(start);
      reverse(cycle.begin(),cycle.end());
      for(int i=0;i<cycle.size();i++)
      {
          cout<<cycle[i]+1<<" ";
      }
  }
  else
  {
      cout<<"NO"<<endl;
  }
}
