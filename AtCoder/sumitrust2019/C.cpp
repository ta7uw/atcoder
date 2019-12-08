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
 * C - 100 to 105
 * https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_c
 *
 * dp[i] 合計金額がちょうど i 円になるような買い方が存在するかどうか。
 */
void Main() {
    int X;
    cin >> X;
    vector<bool> dp(X + 1000, false);
    dp[0] = true;

    rep(i, X) {
        dp[i + 100] = (dp[i + 100] || dp[i]);
        dp[i + 101] = (dp[i + 101] || dp[i]);
        dp[i + 102] = (dp[i + 102] || dp[i]);
        dp[i + 103] = (dp[i + 103] || dp[i]);
        dp[i + 104] = (dp[i + 104] || dp[i]);
        dp[i + 105] = (dp[i + 105] || dp[i]);
    }
    if (dp[X]) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
