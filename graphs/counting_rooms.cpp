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
    // int t;
    // cin >> t;
    // while (t--) {
        int n,k;
        cin>>n>>k;
        vector<vector<char>>v(n,vector<char>(k));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                char x;
                cin>>x;
                v[i][j]=x;
            }
        }
        
        vector<vector<bool>>visited(n,vector<bool>(k,false));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(v[i][j]=='#')
                {
                    visited[i][j]=true;
                }
            }
            
        }
        vector<int>dx={0,0,-1,1};
        vector<int>dy={1,-1,0,0};
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(v[i][j]='.' && !visited[i][j])
                {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[i][j]=true;
                    cnt++;
                    while(!q.empty())
                    {
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int i=0;i<4;i++)
                        {
                            int row=r+dx[i];
                            int col=c+dy[i];
                            
                            if(row>=0 && col>=0 && row<n && col<k && !visited[row][col] && v[row][col]=='.')
                            {
                                q.push({row,col});
                                visited[row][col]=true;
                            }
                        }
                        
                        
                    }
                }
            }
        }
        
        cout<<cnt<<endl;

    // }
}
