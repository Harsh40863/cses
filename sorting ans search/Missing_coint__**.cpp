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
        int ans=1;
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
            
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
           if(ans>=v[i])
           {
               ans+=v[i];
               
           }
           else
           {
               break;
           }
        }
        cout<<ans<<" ";
        
        

    
}
