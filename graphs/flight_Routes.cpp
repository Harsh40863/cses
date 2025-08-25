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
   int n,m,k;
   cin>>n>>m>>k;
   vector<vector<pair<int,int>>>adj(n);
   for(int i=0;i<m;i++)
   {
       int x,y,z;
       cin>>x>>y>>z;
       adj[x-1].push_back({y-1,z});
   }
  multiset<pair<int,int>>s;
  vector<int>ans(n,LLONG_MAX);
  ans[0]=0;
  s.insert({0,0});
  vector<int>ans2;
  vector<int>hh(n,0);
  
  int cnt=0;
  while(!s.empty() )
  {
      auto it=*(s.begin());
      auto tt=s.begin();
      int val=it.second;
      int dist=it.first;
      if(val==n-1)
      {
          ans2.push_back(dist);
          if(ans2.size()>=k)
          {
              break;
          }
      }
      s.erase(tt);
      if(hh[val]>k)
      {
          continue;
      }
      hh[val]++;
      for(auto mt:adj[val])
      {
          
         s.insert({dist+mt.second,mt.first});
      }
      
       
  }
  for(int i=0;i<k;i++)
  {
      cout<<ans2[i]<<" ";
  }
   
    
   
  
}
