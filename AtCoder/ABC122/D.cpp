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

ll dp[100][4][4][4];

void Main() {
    int N;
    cin >> N;
    dp[0][3][3][3] = 1;
    rep(i, N) {
        rep(j, 4) {
            rep(k, 4) {
                rep(m, 4) {
                    rep(l, 4) {
                        if (l == 2 && j == 1 && k == 0) continue;
                        if (l == 2 && j == 0 && k == 1) continue;
                        if (l == 1 && j == 2 && k == 0) continue;
                        if (l == 2 && j == 1 && m == 0) continue;
                        if (l == 2 && k == 1 && m == 0) continue;
                        dp[i + 1][l][j][k] += dp[i][j][k][m];
                        dp[i + 1][l][j][k] %= MOD;
                    }
                }
            }
        }
    }
    ll ans = 0;
    rep(j, 4) {
        rep(k, 4) {
            rep(m, 4) {
                ans += dp[N][j][k][m];
                ans %= MOD;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
