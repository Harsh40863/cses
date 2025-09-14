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
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>pages[i];
    }
    vector<int>dp(m+1,0);
    // iterate over the each book use the power of each book and then use in reverse so that piche wala use naa kar paye
    for(int i=0;i<n;i++) 
    {
        for(int j=m;j>=0;j--)
        {
            if(j>=price[i])
            {
                dp[j]=max(dp[j],dp[j-price[i]]+pages[i]);
            }
        }
    }
    cout<<dp[m]<<endl;
    
    
}
