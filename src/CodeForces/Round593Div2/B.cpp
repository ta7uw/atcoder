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
 *
 * B. Alice and the List of Presents
 * https://codeforces.com/contest/1236/problem/B
 * あるプレゼント x は全ての箱のうち少なくとも一つの箱にいれる必要があるので
 * 各箱に入れる・入れないの 2^M 通りから 1 を引いたものが
 * x を M 個の箱に入れる全てのパターンである。
 * プレゼントは合計 N 種類あるので (2^(M) - 1) ^ N が答え
 */
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

void Main() {
    ll N, M;
    cin >> N >> M;
    ll ans = (pow(2, M, MOD) - 1);
    ans %= MOD;
    ans = pow(ans, N, MOD);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
