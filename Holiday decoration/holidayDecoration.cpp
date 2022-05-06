#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N = 3e5 + 1;
int n, m, k;
int color[MAX_N];
vector<int> graph[MAX_N], v1[MAX_N], v2[MAX_N];
int S;
bool big[MAX_N];
unordered_map<int, int> M[MAX_N];

int get(int v, int col) {
        if (big[v]) {
                return M[v][col];
        }
        int ans = 0;
        for (int to : graph[v]) {
                if (color[to] == col) {
                        ans++;
                }
        }
        return ans;
}

void update(int v, int col) {
        for (int to : v2[v]) {
                if(!--M[to][color[v]]){
                        M[to].erase(color[v]);
                }
                M[to][col]++;
        }
        color[v] = col;
}

int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        cin >> n;
        cin >> m;
        cin >> k;

        for(int i = 1; i <= n; i++) {
            cin >> color[i];
        }

        graph[1].push_back(2);
        graph[2].push_back(1);

        for(int i = 3; i <= n; i++) {
                int parent;
                cin >> parent;
                graph[parent].push_back(i);
                graph[i].push_back(parent);
        }

        S = 550;

        for(int i = 1; i <= n; i++) {
                big[i] = (int) graph[i].size() >= S;
        }

        for(int i = 1; i <= n; i++) {
                for(int to : graph[i]) {
                        if(big[to]) {
                                v2[i].push_back(to);
                        } else {
                                v1[i].push_back(to);
                        }
                }
        }

        for(int i = 1; i <= n; i++) {
                if(big[i]) {
                        for(int to : graph[i]) {
                                M[i][color[to]]++;
                        }
                }
        }

        ll ans = 0;

        for(int i = 1; i <= n; i++) {
                ans += get(i, color[i]);
        }

        ans /= 2;
        while(m--) {
                int pos, col;
                cin >> pos;
                cin >> col;
                ans -= get(pos, color[pos]);
                update(pos, col);
                ans += get(pos, color[pos]);
                cout << ans << '\n';
        }

}