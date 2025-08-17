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
       vector<int>v;
       for(int i=0;i<n;i++)
       {
          v.push_back(i+1);
       }
      
       
       while(v.size()>0)
       {
           vector<int>element;
           for(int i=0;i<v.size();i++)
           {
               if(i%2!=0)
               {
                   cout<<v[i]<<" ";
               }
               else
               {
                   element.push_back(v[i]);
               }
           }
           
           if((v.size())%2!=0 && element.size()>1)
           {
               int j=element[element.size()-1];
               element.pop_back();
               element.insert(element.begin(),j);
           }
           
           v=element;
           if(v.size()==1)
           {
               cout<<v[0]<<" ";
               v.clear();
           }
           
           
           
       }
       
}
