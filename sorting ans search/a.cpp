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
   vector<int>v(n);
   for(int i=0;i<n;i++)
   {
       cin>>v[i];
   }
   vector<int>v1;
   v1.push_back(v[0]);
   for(int i=1;i<n;i++)
   {
       auto k=upper_bound(v1.begin(),v1.end(),v[i]);
       if(k==v1.end())
       {
           v1.push_back(v[i]);
           continue;
       }
       int index=distance(v1.begin(),k);
       v1[index]=v[i];
       
       
       
   }
   
   cout<<v1.size()<<endl;
}