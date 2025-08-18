#include <bits/stdc++.h>

using namespace std;
const long long INF = LLONG_MAX;

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
    int n,m,q;
    cin>>n>>m>>q;
    
    vector<vector<int>>matrix(n,vector<int>(n,INF));
    for(int i=0;i<m;i++)
    {
       int x,y,z;
       cin>>x>>y>>z;
       matrix[x-1][y-1]=min(matrix[x-1][y-1],z);
       matrix[y-1][x-1]=min(matrix[y-1][x-1],z);
       
    }
    vector<pair<int,int>>query;
    for(int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        query.push_back({x-1,y-1});
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                matrix[i][j]=0;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                
                    if(matrix[j][i]<INF && matrix[i][k]<INF )
                    {
                        matrix[j][k]=min(matrix[j][k],matrix[j][i]+matrix[i][k]);
                    }
                
            }
        }
    }
    vector<int>ans(q);
    for(int i=0;i<q;i++)
    {
        if(matrix[query[i].first][query[i].second]==INF)
        {
            ans[i]=-1;
        }
        else
        {
            ans[i]=matrix[query[i].first][query[i].second];
        }
    }
    
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<endl;
    }
    
}
