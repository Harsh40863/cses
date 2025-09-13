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
   int n;
   cin>>n;
   vector<vector<char>>v(n,vector<char>(n));
   vector<vector<int>>dp(n,vector<int>(n,0));
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>v[i][j];
       }
   }
   dp[0][0]=1;
   if(v[0][0]=='*')
   {
       cout<<0<<endl;
   }
   else
   {
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(i-1>=0 && v[i][j]!='*')
               {
                   dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
               }
               if(j-1>=0 && v[i][j]!='*')
               {
                   dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
               }
           }
       }
       cout<<dp[n-1][n-1];
   }
}
