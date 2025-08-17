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
void back(int val, vector < int > & v, map < int, int >&m)
{
    if (val == -1)
    {
        return;
    }
    v.push_back(val);
    back(m[val], v, m);
    return;
}
int32_t main() {
    int n, m;
    cin >> n >> m;
    vector < vector < int >> adj(n);
    vector < bool > visited(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    bool found = false;
    vector < int > v1;
    vector < int > v2;
    for (int i = 0; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            queue < int > q;
            q.push(i);
            visited[i] = true;
            map < int, int > mm;
            mm[i] = -1;
            while (!q.empty())
            {
                int val = q.front();
                q.pop();
                for (auto it: adj[val])
                {
                    if (!visited[it])
                    {
                        q.push(it);
                        visited[it] = true;
                        mm[it] = val;
                    }
                    else if (mm[val] != it && mm[it] != -1)
                    {
                        back(val, v1, mm);
                        back(it, v2, mm);
                        found = true;
                        break;
                    }
 
                }
                if (found)
                {
                    break;
                }
            }
        }
        if(found)
        {
            break;
        }
    }
    if (found)
    {
        int r = v1.size() - 1;
        int l = v2.size() - 1;
        while (v1[r] == v2[l])
        {
            r--;
            l--;
        }
        vector < int > ans;
        int start = v1[0];
        for (int i = 0; i <= r + 1; i++)
        {
            ans.push_back(v1[i]);
        }
        vector < int > t;
        for (int i = 0; i <= l; i++)
        {
            t.push_back(v2[i]);
        }
        reverse(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++)
        {
            ans.push_back(t[i]);
        }
        ans.push_back(start);
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
 
}
