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
 * D - Triangles
 * https://atcoder.jp/contests/abc143/tasks/abc143_d
 *
 * ソートして a と b を決め打ちして c を二分探索で求める。 O (N^2 logN ) で間に合う
 * ソートして枝刈りで N^3 / 6 (1.3 * 10 ^ 10) となり O (N^3) でも間に合うみたいだけど
 * 小さい方からみたときに c の候補は b より大きい範囲に存在することに注意する
 */
void Main() {
    int N;
    cin >> N;
    vector<int> L(N);
    rep(i, N) cin >> L[i];
    sort(L.begin(), L.end());
    int ans = 0;
    rep(i, N) {
        rep2(j, i + 1, N) {
            int a = L[i];
            int b = L[j];
            int idx = lower_bound(L.begin(), L.end(), a + b) - L.begin();
            ans += max(0ll, idx - (j + 1));
        }
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
