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
    int t;
    cin>>t;
    vector<int>query;
    int h=LLONG_MIN;
    for(int i=0;i<t;i++)
    {
        int x;
        cin>>x;
        query.push_back(x);
        h=max(h,x);
    }
    vector<vector<int>>dp(2,vector<int>(h+1,0));
    dp[0][1]=1;
    dp[1][1]=1;
    
    for(int i=2;i<=h;i++)
           {
               dp[0][i]=(4*dp[0][i-1]+dp[1][i-1])%mod;
               dp[1][i]=(dp[0][i-1]+2*dp[1][i-1])%mod;
           }
           for(auto it:query)
           {
               cout<<(dp[0][it]+dp[1][it])%mod<<endl;
           }
}
