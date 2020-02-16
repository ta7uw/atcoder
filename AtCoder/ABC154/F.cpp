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

const int MAX = 3010000;
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
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

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


ll f(ll r, ll c) {
    ll res = COM(r + c + 2, r + 1) % MOD;
    res--;
    return res;
}

/**
 * ABC 154
 * F - Many Many Paths
 *
 * 二次元累積和
 * f(r + 1, c) = f(r, 0) + f(r, 1) + ... + f(r, c) が成り立つ
 * f(r, c) =r+c Cc = (r + c)!/(r!c!) であるので O(1) で f(r + 1, c) がもとまる
 * あとは二次元累積和を使って求めたい矩形の個数を数える
 */
void Main() {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    COMinit();
    ll ans = f(r2, c2);
    ans -= f(r2, c1 - 1);
    if (ans < 0) ans += MOD;
    ans -= f(r1 - 1, c2);
    if (ans < 0) ans += MOD;
    ans += f(r1 - 1, c1 - 1);
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
