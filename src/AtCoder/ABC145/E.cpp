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
 * E - All-you-can-eat
 * https://atcoder.jp/contests/abc145/tasks/abc145_e
 *
 * ナップザックDPに制約がついたもの。
 * dp[i][j] i 番目までの料理から j 分以内に完食できる美味しさの最大値とする。
 * A が昇順になるようにソートしてから遷移を行う
 */
void Main() {
    int N, T;
    cin >> N >> T;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    vector<vector<ll>> dp(N + 1, vector<ll>(T + 3005, 0));
    sort(items.begin(), items.end());
    rep(i, N) {
        P p = items[i];
        rep(t, T + 3001) {
            if (t - p.first >= 0 && T > t - p.first) {
                dp[i + 1][t] = max(dp[i + 1][t], dp[i][t - p.first] + p.second);
            }
            dp[i + 1][t] = max(dp[i + 1][t], dp[i][t]);
        }
    }
    ll ans = 0;
    rep(t, T + 3004) {
        ans = max(ans, dp[N][t]);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
