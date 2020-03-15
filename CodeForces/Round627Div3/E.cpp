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

void Main() {
    ll N, H, L, R;
    cin >> N >> H >> L >> R;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<vector<ll>> dp(N + 1, vector<ll>(H, -1));
    dp[0][0] = 0;
    rep(i, N) {
        ll a = A[i];
        rep(h, H) {
            if (dp[i][h] == -1) continue;
            ll f = (h + a) % H;
            ll f2 = (h + a - 1) % H;
            if (L <= f && f <= R) {
                dp[i + 1][f] = max(dp[i + 1][f], dp[i][h] + 1);
            } else {
                dp[i + 1][f] = max(dp[i + 1][f], dp[i][h]);
            }
            if (L <= f2 && f2 <= R) {
                dp[i + 1][f2] = max(dp[i + 1][f2], dp[i][h] + 1);
            } else {
                dp[i + 1][f2] = max(dp[i + 1][f2], dp[i][h]);
            }

        }
    }
    ll ans = 0;
    rep(i, H) {
        ans = max(ans, dp[N][i]);
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
