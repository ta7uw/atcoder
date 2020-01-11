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
 * A - Falling Asleep
 * https://atcoder.jp/contests/dwacon6th-prelims/tasks/dwacon6th_prelims_a
 */
void Main() {
    ll N;
    cin >> N;
    vector<pair<string, ll>> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    string X;
    cin >> X;
    ll ans = 0;
    bool ok = false;
    rep(i, N) {
        string s = items[i].first;
        ll t = items[i].second;
        if (ok) {
            ans += t;
        }
        if (s == X) {
            ok = true;
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
