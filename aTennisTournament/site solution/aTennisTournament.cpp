//Language: cpp
//ID: 225
//QLink: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/approximate/tennis-tournament-75939265/editorial/
//Author: hacker erth author's solution

#include <iostream>
#include <vector>

#define pb push_back
#define X first
#define Y second
const bool DEBUG = false;
#define cerr if(DEBUG)cerr
#define bit(num,i) ((num>>i)&1)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<long long, long long> pll;
typedef pair<long double, long double> pld;
typedef pair<pii, pii> point;

const long long maxn = 1e5 + 10;
const long long INF = 4e18;
const long long inf = 1e9 + 100;
const long long M = 1e9 + 7;
const long double eps = 0.000001;
const int lg = 21;

const int maxN = 1e5;
const int maxM = 1e5;


int n, m, cvertex, p[maxn];
vector<int> g[maxn];
bool cycle, mark[maxn], black[maxn];
vector<pii> ans;

void dfs(int v) { // to find out whether there exists a cycle or not
    mark[v] = 1;
    black[v] = 1;
    for (auto u : g[v]) {
        if (!mark[u]) {
            p[u] = v;
            dfs(u);
        }
        if (black[u]) { // found a cycle
            int k = v;
            while (k != u) {
                ans.pb(make_pair(p[k], k));
                k = p[k];
            }
            ans.pb(make_pair(v, u));
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i].X + 1 << " " << ans[i].Y + 1 << endl;
            }
            exit(0);
        }
    }
    black[v] = 0;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y, x--, y--;
        g[x].pb(y);
    }

    fill(p, p + maxn, -1);
    for (int i = 0; i < n; i++) {
        if (!mark[i]) {
            dfs(i);
        }
    }

    cout << -1 << endl;

    return 0;
}