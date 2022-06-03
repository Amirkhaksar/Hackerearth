#include <bits/stdc++.h>

using namespace std;

const long long INF = 1LL<<60;
const int MAX = 16;
int N;
vector<long long> A;

vector<vector<long long>> calc(vector<long long> &a, int limit = 0) {
    vector<vector<long long>> dp(N+1, vector<long long>(MAX, INF));
    for (int j = 0; j < MAX; ++j) dp[0][j] = 0, dp[1][j] = j*2 + limit;
    for (int i = 1; i < N; ++i) {
        long long s = a[N-i-1];
        for (int j = 0; j < MAX; ++j) {
            long long t = a[N-i];
            int need = 0;
            while (s > t) ++need, t *= 4;
            long long add = 0;

            if (need >= MAX) {
                add = (need - MAX + 1) * i * 2;
                need = MAX-1;
            }
            dp[i+1][j] = min(dp[i][need] + j * 2 + add + limit , dp[i+1][j]);
            s *= 4;
        }
    }
    return dp;
}

long long solve() {
    vector<vector<long long>> suff = calc(A);
    reverse(A.begin(), A.end());
    vector<vector<long long>> pre = calc(A, 1);
    long long res = INF;
    for (int i = 0; i <= N; ++i) {
     res = min(res ,pre[i][0] + suff[N-i][0] );
    }
    return res;
}
 
int main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    cout << solve() << endl;
}