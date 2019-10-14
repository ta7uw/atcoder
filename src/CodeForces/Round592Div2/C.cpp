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
 * C. The Football Season
 * https://codeforces.com/contest/1244/problem/C
 *
 * 引き分けの回数は最大でも W - 1 回なので引き分け回数を全探索して条件を満たす部分を探す。
 */
void Main() {
    ll N, P, W, D;
    cin >> N >> P >> W >> D;

    rep(i, W) {
        if (i > N || i * D > P) continue;
        if ((P - i * D) % W != 0) continue;
        ll x = (P - i * D) / W;
        if (x + i > N) continue;
        cout << x << " " << i << " " << N - i - x << '\n';
        return;
    }
    cout << -1 << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
