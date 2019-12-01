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
 * C. Ivan the Fool and the Probability Theory
 * https://codeforces.com/contest/1248/problem/C
 * 列と行の場合の数はフィボナッチ数列になっている
 * 1列と1行の塗り方を決めるとそのほかの行と列の塗り方も決まるので
 * 答えは  2 * ( Fn + Fm −1 )
 */

ll dp[100005];

void Main() {
    int N, M;
    cin >> N >> M;

    dp[0] = 1;
    dp[1] = 1;
    rep2(i, 1, max(N, M)) {
        dp[i + 1] = dp[i] + dp[i - 1];
        dp[i + 1] %= MOD;
    }
    cout << 2 * ((dp[N] + dp[M] - 1) % MOD) % MOD << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
