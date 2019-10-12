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

/**
 * E - Get Everything
 * https://atcoder.jp/contests/abc142/tasks/abc142_e
 * ビットDP (bitDP) もらうDP実装
 * 詳細は E.cpp と同じ
 */
void Main() {
    int N, M;
    cin >> N >> M;
    vector<P> items(M);
    rep(i, M) {
        ll a, b;
        cin >> a >> b;
        ll t = 0;
        rep(i, b) {
            int c;
            cin >> c;
            c--;
            t |= 1 << c;
        }
        items[i] = make_pair(a, t);
    }
    vector<vector<ll>> dp(M + 1, vector<ll>(1 << N, INF));
    rep(i, M + 1) {
        dp[i][0] = 0;
    }
    rep(i, M) {
        P p = items[i];
        rep(j, (1 << N)) {
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            dp[i + 1][j | p.second] = min(dp[i + 1][j | p.second], dp[i][j] + p.first);
        }
    }
    if (dp[M][(1 << N) - 1] == INF) {
        cout << -1 << '\n';
    } else {
        cout << dp[M][(1 << N) - 1] << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
