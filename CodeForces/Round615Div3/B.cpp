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

void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N;
        cin >> N;
        vector<P> items(N);
        rep(i, N) cin >> items[i].second >> items[i].first;
        sort(items.begin(), items.end());
        string ans = "";
        bool ok = true;
        ll last_x = 0;
        ll last_y = 0;
        rep(i, N) {
            ll x = items[i].second;
            ll y = items[i].first;
            ll r = x - last_x;
            ll u = y - last_y;
            if (r >= 0 && u >= 0) {
                rep(j, r) {
                    ans += 'R';
                }
                rep(j, u) {
                    ans += 'U';
                }
            } else {
                ok = false;
                break;
            }
            last_x = x;
            last_y = y;
        }
        if (ok) {
            cout << "YES" << '\n';
            cout << ans << '\n';
        } else {
            cout << "NO" << '\n';
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
