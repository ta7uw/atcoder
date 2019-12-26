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
 * E - Double Factorial
 * https://atcoder.jp/contests/abc148/tasks/abc148_e
 * N/10 から順に、分母が N 以下の間、分母を 5 倍して商
 * を求めるというのを繰り返し、総和を取ればよいです
 */
void Main() {
    ll N;
    cin >> N;
    if (N % 2 == 1) {
        cout << 0 << '\n';
    } else {
        ll ans = 0;
        rep2(i, 1, 26) {
            ll tmp = N;
            ll cnt = 0;
            ll d = 2 * (ll) pow(5, i);
            ans += tmp / d;
        }
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
