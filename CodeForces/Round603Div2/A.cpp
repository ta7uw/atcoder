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
 * A. Sweet Problem
 * https://codeforces.com/contest/1263/problem/A
 *
 * r, g, b の中で最も大きいもが他の2つの和より大きいかどうかで場合分け
 */
void Main() {
    int T;
    cin >> T;
    rep(x, T) {
        ll r, g, b;
        cin >> r >> g >> b;
        vector<int> can;
        can.push_back(r);
        can.push_back(g);
        can.push_back(b);
        sort(can.begin(), can.end());
        ll ans = 0;

        ll f = can[0];
        ll s = can[1];
        ll t = can[2];
        ll mar = t - s;
        ans += f;
        if (mar >= f) {
            t -= f;
        }else{
            t -= mar;
            f -= mar;
            ll y = (f + 1) / 2;
            t -= y;
            s -= f - y;
        }
        ans += min(s, t);
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
