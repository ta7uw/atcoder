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
 * E - Colorful Hats 2
 * https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e
 *
 * これまでに出現した a の値の個数を記録しておき答えに順にかけていく。
 * 出現した a の個数を 1 減らし a + 1 を 1 増やす操作を行っていく
 */
void Main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> cnt(N + 1, 0);
    cnt[0] = 3;
    ll ans = 1;
    rep(i, N) {
        int a = A[i];
        ans *= cnt[a];
        ans %= MOD;
        cnt[a]--;
        cnt[a + 1]++;
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
