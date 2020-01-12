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

ll mod_inverse(ll a, ll mod) {
    ll b = mod, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= mod;
    if (u < 0) u += mod;
    return u;
}

/**
 * B - Fusing Slimes
 * https://atcoder.jp/contests/dwacon6th-prelims/submissions/9432346
 *
 * 各区間を通るスライムの個数の期待値を求め、各区間の大きさをかける。
 * これの和に (N-1)! をかけたものが答え
 * 各区間を通るスライムの個数は
 * Cn = Cn-1 + 1/n
 * で合わすことができる
 */
void Main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];

    vector<ll> C(N);
    C[0] = 1;
    rep(i, N - 1) {
        C[i + 1] += C[i] + mod_inverse(i + 2, MOD);
    }
    ll ans = 0;
    rep(i, N - 1) {
        ll dis = A[i + 1] - A[i];
        ans += dis * C[i];
        ans %= MOD;
    }
    rep2(i, 1, N) {
        ans *= i;
        ans %= MOD;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
