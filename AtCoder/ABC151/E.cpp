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
const int MAX = 510000;

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

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

/**
 * E - Max-Min Sums
 * https://atcoder.jp/contests/abc151/tasks/abc151_e
 *
 * A を昇順にソートしてから sum(max X) - sum(min X) を求める
 * min を固定するとその他の a は min となる a 以上なので COM(N - (i + 1), K - 1) 通り存在する。
 * よって sum(min X) = ai * COM(N - (i + 1), K - 1)
 * 同様に考えると sum(max X) = (a * COM(i, K - 1))
 * 各値が何度足されるのか、引かれるのかをみる典型
 */
void Main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    ll ans = 0;
    COMinit();

    ll minus = 0;
    rep(i, N - K + 1) {
        ll max_i = i + K - 1;
        ll a = A[i];
        minus += (a * COM(N - (i + 1), K - 1)) % MOD;
        minus %= MOD;
        if (minus < 0) minus += MOD;
    }
    ll plus = 0;

    rep2(i, K - 1, N) {
        ll a = A[i];
        plus += (a * COM(i, K - 1)) % MOD;
        plus %= MOD;
        if (plus < 0) plus += MOD;
    }
    ans = plus - minus;
    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
