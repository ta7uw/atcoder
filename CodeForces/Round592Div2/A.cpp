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
 * A. Pens and Pencils
 * https://codeforces.com/contest/1244/problem/A
 *
 * pen と pencil ともに必要な数を ceil で求めて k を超えないか判定する
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        int ans_a = (a + c - 1) / c;
        int ans_b = (b + d - 1) / d;
        if (ans_a + ans_b <= k) {
            cout << ans_a << " " << ans_b << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
