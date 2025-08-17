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
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        adj[x-1].push_back({y-1,z});
        
    }
    vector<int>ans(n,LLONG_MAX);
    set<pair<int,int>>s;
    s.insert({0,0});
    ans[0]=0;
    while(!s.empty())
    {
        auto it=*(s.begin());
        int dist=it.first;
        int val=it.second;
        s.erase(it);
        for(auto mt:adj[val])
        {
            if(dist+mt.second<ans[mt.first])
            {
                if(ans[mt.first]!=LLONG_MAX)
                {
                    s.erase({ans[mt.first],mt.first});
                    
                }
                ans[mt.first]=dist+mt.second;
                s.insert({ans[mt.first],mt.first});
            }
        }
    }
    
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i]!=LLONG_MAX)
        {
            cout<<ans[i]<<" ";
        }
        
    }
    cout<<endl;
}
