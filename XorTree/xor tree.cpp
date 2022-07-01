#include <memory.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cctype>
#include <cstring>
#include <climits>
#include <cmath>
#include <vector>
#include <string>
#include <memory>
#include <numeric>
#include <limits>
#include <functional>
#include <tuple>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#ifndef __GNUC__
#include <intrin.h>
#endif
#include <immintrin.h>

using namespace std;

#define PROFILE_START(i)    clock_t start##i = clock()
#define PROFILE_STOP(i)     fprintf(stderr, "elapsed time (" #i ") = %f\n", double(clock() - start##i) / CLOCKS_PER_SEC)

typedef long long           ll;
typedef unsigned long long  ull;

const int MAXN = 100'000;
const int LOGN = 18;

namespace Tree {
    int N;                          // the number of vertex

    vector<int> edges[MAXN];        // edges (vertex number)
    int P[LOGN][MAXN];              // P[0][n] points to the parent

    int level[MAXN];                // depth (root is 0)

    int xxor[MAXN];
    int currXor[MAXN];
    int nextXor[MAXN];

    void clear() {
        for (int i = 0; i < N; i++) {
            edges[i].clear();
            xxor[i] = 0;
            currXor[i] = 0;
            nextXor[i] = 0;
        }
        N = 0;
    }

    void addEdge(int u, int v) {
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    //--- build

    void dfs(int u, int parent) {
        P[0][u] = parent;

        for (int v : edges[u]) {
            if (v == parent)
                continue;

            level[v] = level[u] + 1;
            dfs(v, u);
        }
    }

    void makeLcaTable() {
        for (int i = 1; i < LOGN; i++) {
            for (int j = 0; j < N; j++) {
                int pp = P[i - 1][j];
                P[i][j] = pp < 0 ? pp : P[i - 1][pp];
            }
        }
    }

    void build(int root) {
        level[root] = 0;
        dfs(root, -1);
        makeLcaTable();
    }

    //--- LCA

    int climbTree(int node, int dist) {
        if (dist <= 0)
            return node;

        for (int i = 0; dist > 0; i++) {
            if (dist & 1)
                node = P[i][node];
            dist >>= 1;
        }

        return node;
    }

    int findLCA(int A, int B) {
        if (level[A] < level[B])
            swap(A, B);

        A = climbTree(A, level[A] - level[B]);

        if (A == B)
            return A;

        int bitCnt = 0;
        for (int x = level[A]; x; x >>= 1)
            bitCnt++;

        for (int i = bitCnt - 1; i >= 0; i--) {
            if (P[i][A] > 0 && P[i][A] != P[i][B]) {
                A = P[i][A];
                B = P[i][B];
            }
        }

        return P[0][A];
    }

    int distance(int u, int v) {
        return level[u] + level[v] - level[findLCA(u, v)] * 2;
    }
}


ll gAns = 0;

int dfsSum(int u, int parent) {
    int xxor = Tree::currXor[u];
    for (auto v : Tree::edges[u]) {
        if (v == parent)
            continue;
        xxor ^= dfsSum(v, u);
    }

    gAns += xxor ^ Tree::xxor[u];
    xxor ^= Tree::nextXor[u];

    return xxor;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0) {
        int Q;
        int u, v, w;

        cin >> Tree::N >> Q;
        for (int i = 1; i < Tree::N; i++) {
            cin >> u >> v;
            u--;
            v--;
            Tree::addEdge(u, v);
        }
        Tree::build(0);

        while (Q-- > 0) {
            cin >> u >> v >> w;

            u--;
            v--;

            if (u == v) {
                Tree::xxor[u] ^= w;
                continue;
            }

            int lca = Tree::findLCA(u, v);

            if (u != lca && v != lca) {
                Tree::currXor[u] ^= w;
                Tree::currXor[v] ^= w;
                Tree::currXor[lca] ^= w;
                Tree::nextXor[lca] ^= w;
            } else {
                if (u == lca)
                    swap(u, v);
                Tree::currXor[u] ^= w;
                Tree::nextXor[lca] ^= w;
            }
        }

        gAns = 0;
        dfsSum(0, -1);
        cout << gAns << endl;

        if (T > 0)
            Tree::clear();
    }

    return 0;
}
