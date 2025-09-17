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
bool isvalid(int k,int m)
{
    if(k<=0 || k>m)
    {
        return false;
    }
    return true;
}

int32_t main() {
    int n,m;
    cin>>n>>m;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=1;i<=m;i++)
    {
        if(v[0]==i || v[0]==0)
        {
            dp[1][i]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(v[i-1]!=0 && j!=v[i-1])
            {
                dp[i][j]=0;
            }
            else
            {
                for(int k=j-1;k<=j+1;k++)
                {
                    if(isvalid(k,m))
                    {
                        dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=m;i++)
    {
        sum=(sum+dp[n][i])%mod;
    }
    cout<<sum<<endl;
   
}
