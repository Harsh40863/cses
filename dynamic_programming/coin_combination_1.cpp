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
    int n,sum;
    cin>>n>>sum;
    vector<int>v(n);
    vector<int>dp(sum+1,0);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        // if(v[i]<=sum)
        // {
        //     dp[v[i]]++;
        // }
        
    }
    dp[0]=1;
    
    for(int i=0;i<=sum;i++)
    {
        for(auto it:v)
        {
            if(i>=it)
            {
                dp[i]=(dp[i]+dp[i-it])%mod;
            }
        }
    }
    // cout<<endl;
   cout<<dp[sum]<<endl;
    
}
