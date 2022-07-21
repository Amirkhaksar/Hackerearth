/*
#Language:C++
#ID:Handshakes in a party
#QLink:https://www.hackerearth.com/problem/algorithm/handshakes-4-de17857e/
#All Accepet
#Author:Amirkhaksar
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1010;

int n;
int id[maxn][maxn];
int k = 1;

vector<int> g[maxn * maxn];
int indeg[maxn * maxn];

int tot;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);  cout.tie(0);
    cin >> n;
    tot = n * (n - 1) / 2;

    for (int i = 0; i < n; i++) {
        int prev = 0;
        for (int j = 1; j < n; j++) {
            int x;
            cin >> x;
            --x;

            // assign a unique id to the G(i)-G(x) handshake
            if (!id[i][x]) {
                id[i][x] = id[x][i] = k;
                k++;
            }

            // create handshake sequence graph 
            if (prev) {
                g[prev].push_back(id[i][x]);
                indeg[id[i][x]]++;
            }
            prev = id[i][x];
        }
    }


    // add all handshakes which doesn't need prior handshake as source nodes in queue.
    queue<int> Q;
    int count = 0;
    for (int i = 1; i < k; i++) {
        if (indeg[i] == 0) {
            Q.push(i);
            count++;
        }
    }

    ll seconds = 0;
    // multi-point BFS to traverse and visit every node in directed graph
    while (!Q.empty()) {
        int len = Q.size();
        queue<int> nQ;
        while (!Q.empty()) {
            int front_node = Q.front();
            Q.pop();
            for (int x : g[front_node]) {
                if (--indeg[x] == 0) {
                    nQ.push(x);
                    count++;
                }
            }
        }
        Q = nQ;
        seconds++;
    }

    // count denotes the number of visited nodes in the graph
    // if the visited nodes are equal to total handshakes in the party, then the data is valid
    if (count == tot)
        cout << seconds * 3 << endl;
    else
        cout << -1 << endl;
    return 0;
}