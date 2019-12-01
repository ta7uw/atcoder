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

// 素因数分解
map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}

ll pow(ll b, ll e, ll mod) {
    ll res = 1;
    while (e > 0) {
        if ((e & 1) == 1) {
            res = (res * b) % mod;
        }
        b = (b * b) % mod;
        e >>= 1;
    }
    return res;
}

/**
 * C. Primes and Multiplication
 * https://codeforces.com/contest/1228/problem/C
 * Xを素因数分解して、素数を列挙する。
 * 各素数のべき乗の値でNが何回割れるかを数えていく。
 * その合計を用いてpow(base, cnt, MOD)を求めて掛け合わせていく
 * オーバーフローに注意
 */
void Main() {
    ll X, N;
    cin >> X >> N;
    map<ll, ll> pf = prime_factorize(X);
    vector<ll> tar;
    for (P p : pf) {
        tar.push_back(p.first);
    }
    ll ans = 1;
    rep(i, tar.size()) {
        ll t = tar[i];
        ll e = 1;ll
        beki_cnt = 0;
        while ((ll) t * e <= N && t * e >= t * (e/t)) {
            beki_cnt += N / (t * e);
            e = t * e;
        }
        ans *= pow(t, beki_cnt, MOD);
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
