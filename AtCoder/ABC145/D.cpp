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

const int MAX = 910000;
long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/**
 * D - Knight
 * https://atcoder.jp/contests/abc145/tasks/abc145_d
 *
 * (i + 1, j + 2) が n 回、(i + 2, j + 1) が m 回で (X, Y) に到達できるとすると
 * n + 3m = X, 3n + m = Y なのでこれを満たすか判定する。
 * 答えは n + m 回の移動のうちどの n 回で (i + 1, j + 2) を使うかなので (n + m)Cn で求めることができる
 */
void Main() {
    ll X, Y;
    cin >> X >> Y;
    if ((X + Y) % 3 != 0) {
        cout << 0 << '\n';
    } else {
        if (2 * X - Y < 0 || 2 * Y - X < 0) {
            cout << 0 << '\n';
        } else {
            COMinit();
            cout << COM((X + Y) / 3, X - (X + Y) / 3) % MOD<< '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
