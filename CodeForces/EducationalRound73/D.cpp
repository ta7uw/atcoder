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

void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int N;
        cin >> N;
        vector<P> items(N);
        rep(i, N) {
            cin >> items[i].first >> items[i].second;
        }

        vector<vector<ll>> dp(N + 1, vector<ll>(3, INF));

        rep(i, N) {
            ll a = items[i].first;
            ll b = items[i].second;
            if (i == 0) {
                rep(j, 3) {
                    dp[i + 1][j] = b * j;
                }
            } else {
                rep(j, 3) {
                    rep(k, 3) {
                        if (items[i - 1].first + k != a + j) {
                            dp[i + 1][j] = min(dp[i + 1][j], dp[i][k] + b * j);
                        }
                    }
                }
            }
        }
        cout << min({dp[N][0], dp[N][1], dp[N][2]}) << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
