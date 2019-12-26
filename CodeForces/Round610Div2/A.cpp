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
 * A. Temporarily unavailable
 * https://codeforces.com/contest/1282/problem/A
 *
 * c が a, b に対してどの範囲に位置するかを場合分け
 * そのあと r によってどの範囲が無効になるかを場合わけ
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll a, b, c, r;
        cin >> a >> b >> c >> r;
        ll max_num = max(a, b);
        ll min_num = min(a, b);
        ll ans = 0;
        if (c <= min_num) {
            if (c + r < max_num) {
                ans = abs(max(c + r, min_num) - max_num);
            } else {
                ans = 0;
            }
        } else if (min_num < c && c <= max_num) {
            if (abs(c - min_num) > r) {
                ans += abs(c - min_num) - r;
            }
            if (abs(max_num - c) > r) {
                ans += abs(c - max_num) - r;
            }
        } else {
            if (c - r < min_num) {
                ans = 0;
            } else {
                ans = abs(min(c - r, max_num) - min_num);
            }
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
