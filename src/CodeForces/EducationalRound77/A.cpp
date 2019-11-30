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
 * A. Heating
 * https://codeforces.com/contest/1260/problem/A
 *
 * なるべくコストが均等になるように分配する
 * k の最小値が x のとき最大値は x + 1 が最適
 */
void Main() {
    int N;
    cin >> N;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    rep(i, N) {
        P p = items[i];
        ll f = p.first;
        ll s = p.second;
        if (f >= s) {
            cout << s << '\n';
        } else {
            vector<ll> cnt;
            rep(i, f) {
                ll tmp = s / f;
                cnt.push_back(tmp);
            }
            ll d = s % f;
            rep(i, d) {
                cnt[i] += 1;
            }
            ll ans = 0;
            rep(i, f) {
                ans += cnt[i] * cnt[i];
            }
            cout << ans << '\n';
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
