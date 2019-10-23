#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

/**
 * For DEBUG
 * https://github.com/ta7uw/cpp-pyprint
 */
#include "cpp-pyprint/pyprint.h"

#endif

ll dp[200005][2];

/**
 * E. By Elevator or Stairs?
 * https://codeforces.com/contest/1249/problem/E
 *
 * dp[i][j] i　階目にとうたつするために j (0: 階段, 1: エレベータ) で到達するための最小コスト
 * と定義して遷移を求めていく。
 */
void Main() {
    int N, C;
    cin >> N >> C;
    vector<ll> A(N - 1);
    rep(i, N - 1) cin >> A[i];
    vector<ll> B(N - 1);
    rep(i, N - 1) cin >> B[i];

    dp[0][0] = 0;
    dp[0][1] = C;
    rep(i, N) {
        dp[i + 1][0] = min({dp[i][0] + A[i], dp[i][1] + A[i]});
        dp[i + 1][1] = min({dp[i][0] + B[i] + C, dp[i][1] + B[i]});
    }

    rep(i, N) {
        cout << min(dp[i][0], dp[i][1]) << ' ';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
