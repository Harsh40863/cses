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
void back(int row,int col,int res_row,int res_col,map<pair<int,int>,pair<int,int>>&m,string &str)
{
    if(row==res_row && col==res_col)
    {
        reverse(str.begin(),str.end());
        return;
    }
    if(m[{row,col}].first==row-1)
    {
        str.push_back('D');
        back(m[{row,col}].first,col,res_row,res_col,m,str);
    }
    else if(m[{row,col}].first==row+1)
    {
        str.push_back('U');
        back(m[{row,col}].first,col,res_row,res_col,m,str);
    }
    else if(m[{row,col}].second==col-1)
    {
        str.push_back('R');
        back(row,m[{row,col}].second,res_row,res_col,m,str);
    }
    else if(m[{row,col}].second==col+1)
    {
        str.push_back('L');
        back(row,m[{row,col}].second,res_row,res_col,m,str);
    }
    return;
}
int32_t main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            grid[i][j]=c;
        }
    }
    vector<int>dx={0,0,-1,1};
    vector<int>dy={1,-1,0,0};
    queue<pair<char,pair<int,int>>>q;
    pair<int,int>ad;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='M')
            {
                q.push({'M',{i,j}});
                grid[i][j]='#';
            }
            if(grid[i][j]=='A')
            {
                ad.first=i;
                ad.second=j;
            }
        }
    }
    q.push({'A',{ad.first,ad.second}});
    map<pair<int,int>,pair<int,int>>mu;
    bool found=false;
    string str;
    while(!q.empty())
    {
        int r=q.front().second.first;
        int c=q.front().second.second;
        char who=q.front().first;
        if((r==0 || r==n-1 || c==0 || c==m-1) && who=='A')
        {
           back(r,c,ad.first,ad.second,mu,str);
           found=true;
           break;
        }
        q.pop();
        for(int i=0;i<4;i++)
        {
            int row=r+dx[i];
            int col=c+dy[i];
            if(row>=0 && col>=0 && row<n && col<m && grid[row][col]!='#')
            {
                if(who=='M')
                {
                    
                    q.push({'M',{row,col}});
                }
                else
                {
                    q.push({'A',{row,col}});
                    mu[{row,col}]={r,c};
                }
                grid[row][col]='#';
            }
            
        }
    }
    
    if(found)
    {
        cout<<"YES"<<endl;
        cout<<str.size()<<endl;
        cout<<str;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
    
    
    
    
    
}
