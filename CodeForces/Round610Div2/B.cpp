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
 * B2. K for the Price of One (Hard Version)
 * https://codeforces.com/contest/1282/problem/B2
 *
 * ソートしてから DP
 * dp[i][0] を i 番目を普通に買った場合、,dp[i][1] を i 番目をセールで買った場合とする
 * dp[i + 1][1] は dp[i + 1 - K][0] dp[i + 1 - K][1] から遷移することに注意する
 */
void Main() {
    ll T;
    cin >> T;
    rep(t, T) {
        ll N, P, K;
        cin >> N >> P >> K;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];
        sort(A.begin(), A.end());
        vector<vector<ll>> dp(N + 1, vector<ll>(2, INF));
        dp[0][0] = 0;
        rep(i, N) {
            ll a = A[i];
            if (i + 1 - K >= 0) {
                dp[i + 1][1] = min(dp[i - K + 1][0], dp[i - K + 1][1]) + a;
            }
            dp[i + 1][0] = min(dp[i][1], dp[i][0]) + a;
        }
        ll ans = 0;
        rep(i, N) {
            if (dp[i + 1][0] <= P) {
                ans = i + 1;
            }
            if (dp[i + 1][1] <= P) {
                ans = i + 1;
            }
        }
        cout << ans << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
