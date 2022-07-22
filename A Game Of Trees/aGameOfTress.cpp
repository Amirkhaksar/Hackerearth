#include <bits/stdc++.h>

using namespace std;

/**
 * id: 244
 * author: amir aghazadeh (cssu-ama)
 * question link: https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/tree-game-2-e6796bef/
 * language: cpp
 */

typedef long long ll;

const int maxn = 5e4 + 14, maxd = 16;

struct Trie {
    int lazy;
    vector<array<int, 2> > t;
    vector<int> cnt;

    Trie() : lazy(0), t(1), cnt(1) {}

    void add(int x, bool final = false) {
        if (!final)
            x ^= lazy;
        int p = 0;
        for (int b = maxd - 1; b >= 0; b--) {
            int dir = x >> b & 1;
            if (!t[p][dir])
                if (!final) {
                    add(x, true);
                    return;
                }
                else {
                    t[p][dir] = t.size();
                    t.push_back({});
                    cnt.push_back(0);
                }
            p = t[p][dir];
            cnt[p] += final;
        }
    }

    int mex() {
        int p = 0, ans = 0;
        for (int b = maxd - 1; b >= 0; b--) {
            int dir = lazy >> b & 1;
            if (!t[p][dir])
                return ans;
            else if (cnt[t[p][dir]] < 1 << b)
                p = t[p][dir];
            else {
                ans |= 1 << b;
                if (!t[p][!dir])
                    return ans;
                p = t[p][!dir];
            }
        }
        assert(false);
    }

    void dfs(vector<int> &elements, int v = 0, int val = 0, int h = maxd) {
        if (h == 0) {
            elements.push_back(val ^ lazy);
            return;
        }
        if (t[v][0])
            dfs(elements, t[v][0], val, h - 1);
        if (t[v][1])
            dfs(elements, t[v][1], val | 1 << h - 1, h - 1);
    }

    vector<int> get_elements() {
        vector<int> elements;
        dfs(elements);
        return elements;
    }
    Trie &operator+=(Trie &o) {
        if(o.t.size() > t.size())
            swap(*this, o);
        for (auto x : o.get_elements())
            add(x);
        return *this;
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> g[n];
        for (int i = 1; i < n; ++i) {
            int p;
            cin >> p;
            p--;
            g[p].push_back(i);
        }
        Trie sack[n];
        int grundy[n];
        for (int v = n - 1; v >= 0; v--) {
            int child_grundy = 0;
            for(auto child : g[v])
                child_grundy ^= grundy[child];
            for(auto child : g[v]){
                sack[child].lazy ^= child_grundy ^ grundy[child];
                sack[v] += sack[child];
            }
            grundy[v] = sack[v].mex();
            sack[v].add(child_grundy);
        }
        cout << (grundy[0] ? "A\n" : "B\n");
    }
}