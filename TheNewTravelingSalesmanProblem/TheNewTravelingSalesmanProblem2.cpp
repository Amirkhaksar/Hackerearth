// Language: Python3.9
// ID: tzp-5a83020f
// QLink:https://www.hackerearth.com/practice/algorithms/graphs/graph-representation/practice-problems/approximate/tzp-5a83020f/
// Author: AmirZoyber

#include <bits/stdc++.h>
#define dbg(x) "[" << #x << ":" << (x) << "]"
using namespace std;
template<typename A,typename B>
ostream& operator<<(ostream& out,const pair<A,B>& p) 
{
    return out << "(" << p.first << ", " << p.second << ")";
}
template<typename T>
ostream& operator<<(ostream& out,const vector<T>& c) 
{
    out << "{";
    for(auto it = c.begin(); it != c.end(); it++) 
	{
        if(it != c.begin()) out << ", ";
        out << *it;
    }
    return out << "}";
}
int n,m;
vector<long long> cst,vsc;
vector<vector<int>> g;
void solve() 
{
    cin >> n >> m;
    cst.resize(m + 1);
    vsc.resize(m + 1);
    g.resize(n + 1);
    for(int i = 0; i < m; i++) 
	{
        int a,b,cost,vis;
        cin >> a >> b >> cost >> vis;
        cst[i + 1] = cost;
        vsc[i + 1] = vis;
        g[a].push_back(i + 1);
        g[b].push_back(i + 1);
    }
    double mn = 1e18;
    int id = 1,idd = 1;
    for(int i = 1; i <= n; i++) 
	{
        for(int x = 0; x < g[i].size(); x++) 
		{
            int a = g[i][x];
            double xx = (n - 2) * cst[a] + (n - 3) * sqrt(2) * vsc[a];
            for(int y = 0; y < g[i].size(); y++) 
			{
                if(x == y) continue;
                int b = g[i][y];
                double yy = xx + cst[b] + sqrt(vsc[a] * vsc[a] + vsc[b] * vsc[b]);
                if(yy < mn) 
				{
                    mn = yy;
                    id = a;
                    idd = b;
                }
            }
        }
    }
    vector<int> ans = {idd};
    for(int i = 1; i < n - 1; i++) ans.push_back(id);
    cout << ans.size() << endl;
    for(int i : ans) 
	{
        cout << i << " ";
    }
    cout << endl;
}
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    for(int i = 1; i <= t; i++) 
	{
        solve();
    }
    return 0;
}