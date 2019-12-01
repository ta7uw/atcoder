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

ll pow(ll x, ll y, ll mod) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return pow(x * x % mod, y / 2, mod) % mod;
    } else {
        return x * pow(x, y - 1, mod) % mod;
    }
}

/**
 * B - Counting of Trees
 * https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_b
 *
 * 基本的には頂点 1 から距離が近い順に見ていって
 * pow(counter[i-1], counter[i], mod) をかけていく。
 * コーナーケースに注意する。
 */
void Main() {
    int N;
    cin >> N;
    ll mod = 998244353L;
    vector<ll> D(N);
    rep(i, N) cin >> D[i];
    ll ans = 1;

    if (D[0] != 0) {
        cout << 0 << '\n';
        return;
    }

    map<ll, ll> counter;
    rep(i, N) {
        counter[D[i]]++;
    }

    if (counter[0] != 1) {
        cout << 0 << '\n';
        return;
    }

    ll max_num = *max_element(D.begin(), D.end());
    ll prev = -1;
    rep2(i, 1, max_num + 1) {
        ll d = counter[i];
        if (i == 1) {
            if (d == 0) {
                cout << 0 << '\n';
                return;
            }
        } else {
            if (d == 0) {
                cout << 0 << '\n';
                return;
            } else {
                ans *= (ll) pow(prev, d, mod);
                ans %= mod;
            }
        }
        prev = d;
    }
    cout << ans % mod << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
