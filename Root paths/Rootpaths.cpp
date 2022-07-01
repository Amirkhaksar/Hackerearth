/*
@language: cpp
#ID:Root paths
#QLink:https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/root-path-d65f3397/
#All Accepet
#Author:Amirkhaksar
*/


#include <iostream>
#include <vector>

using namespace std;

class Solver {
public:

    int n, q, t;
    vector <int> color;
    vector <vector<int> > G;
    
    Solver(int nn) {
        n = nn;
        color.resize(n + 1);
        G.resize(n + 1);
        color[1] = 1;

    }


    inline void repaint(int x) {
        while (!G[x].empty()) {
            int to = G[x].back();
            G[x].pop_back();

            if (color[to]) {
                continue;
            }
            else {
                color[to] = 1;
                repaint(to);
            }
        }
    }

    inline void add_edge(int u, int v) {
        if (color[v]) {
            return;
        }
        if (color[u]) {
            color[v] = 1;
            repaint(v);
        }
        else {
            G[u].push_back(v);
        }
    }

    inline int get_ans(int x) {
        if (color[x]) {
            return x;
        }
        return 0;
    }

};
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q, t;
    cin >> n >> q >> t;

    Solver* s = new Solver(n);
    int lastans = 0;
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            a = (a ^ (t * lastans)) % n + 1;
            b = (b ^ (t * lastans)) % n + 1;
            s->add_edge(a, b);
        }
        else {
            int a;
            cin >> a;
            a = (a ^ (t * lastans)) % n + 1;
            lastans = s->get_ans(a);
            cout << lastans << '\n';
        }
    }

    return 0;
}
