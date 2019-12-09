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
 * D - Xor Sum 4
 * https://atcoder.jp/contests/abc147/tasks/abc147_d
 * XOR の操作では各 bit は互いに干渉しないため bit の桁ごとに考える
 * Ai が 0 のときは 1 , 1 のときは 0 の個数を数え、その bit 桁の値をかける
 */
void Main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll ans = 0;
    unordered_map<ll, ll> cnt;
    rep(i, N) {
        ll a = A[i];
        rep(j, 61) {
            if (a & (1LL << j)) {
                cnt[j]++;
            }
        }
    }
    rep(i, N) {
        ll a = A[i];
        rep(j, 61) {
            if (a & (1LL << j)) {
                cnt[j]--;
            }
        }
        rep(j, 61) {
            if (a & (1LL << j)) {
                ll tmp = 1LL << j;
                tmp %= MOD;
                ll mul = N - (i + 1) - cnt[j];
                ans += tmp * mul;
                ans %= MOD;
            } else {
                ll tmp = 1LL << j;
                tmp %= MOD;
                ll mul = cnt[j];
                ans += tmp * mul;
                ans %= MOD;
            }
        }
    }
    cout << ans % MOD << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
