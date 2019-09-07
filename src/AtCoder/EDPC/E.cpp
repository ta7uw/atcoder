#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector<vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;

#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

ll dp[105][110005];

void Main() {
    int N, W;
    cin >> N >> W;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    fill(dp[0], dp[105], INF);

    rep(i, N) {
        dp[i][0] = 0;
    }
    rep(i, N) {
        rep(j, N * 1100) {
            if (j - items[i].second >= 0) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - items[i].second] + items[i].first);
            }
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
        }
    }
    ll ans = INF;
    rrep(i, 110005, 0) {
        if (dp[N][i] <= W) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
