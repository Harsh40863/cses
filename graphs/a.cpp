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
void back(string &str, map<pair<int,int>,char>&m,int row,int col,vector<vector<char>>&v)
{
    if(v[row][col]=='A')
    {
        reverse(str.begin(),str.end());
        return;
    }
    if(m[{row,col}]=='R')
    {
        str.push_back('R');
        back(str,m,row,col-1,v);
    }
    else if(m[{row,col}]=='L')
    {
        str.push_back('L');
        back(str,m,row,col+1,v);
    }
    else if(m[{row,col}]=='U')
    {
        str.push_back('U');
        back(str,m,row+1,col,v);
    }
    else if(m[{row,col}]=='D')
    {
        str.push_back('D');
        back(str,m,row-1,col,v);
    }
    
    return;
    
}
int32_t main() {
    int n,k;
    cin>>n>>k;
    int rol=-1;
    int cow=-1;
    int e_r=-1;
    int e_c=-1;
    vector<vector<char>>v(n,vector<char>(k));
    vector<vector<bool>>visited(n,vector<bool>(k));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<k;j++)
        {
            char x;
            cin>>x;
            v[i][j]=x;
            if(x=='A')
            {
                rol=i;
                cow=j;
            }
            if(x=='#')
            {
                visited[i][j]=true;
            }
        }
    }
    queue<pair<int,pair<int,int>>>q;
    map<pair<int,int>,char>m;
    q.push({0,{rol,cow}});
    m[{rol,cow}]='r';
    vector<int>dx={0,0,-1,1};
    vector<int>dy={1,-1,0,0};
    visited[rol][cow]=true;
    int lol=-1;
    while(!q.empty())
    {
        int level=q.front().first;
        int r=q.front().second.first;
        int c=q.front().second.second;
        q.pop();
        if(v[r][c]=='B')
        {
            lol=level;
            e_r=r;
            e_c=c;
            break;
        }
        for(int i=0;i<4;i++)
        {
            int row=r+dx[i];
            int col=c+dy[i];
            
            if(row>=0 && col>=0 && row<n && col<k && !visited[row][col] && (v[row][col]=='.' || v[row][col]=='B') )
            {
                if(row==r+1)
                {
                   m[{row,col}]='D';
                }
                else if(row==r-1)
                {
                    m[{row,col}]='U';
                }
                else if(col==c+1)
                {
                    m[{row,col}]='R';
                }
                else if(col==c-1)
                {
                    m[{row,col}]='L';
                }
                q.push({level+1,{row,col}});
                visited[row][col]=true;
            }
        }
        
    }
    if(lol==-1)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        cout<<lol<<endl;
        string str;
        back(str,m,e_r,e_c,v);
        cout<<str<<endl;
    }
    
}