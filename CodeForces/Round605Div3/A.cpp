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
 * A. Three Friends
 * https://codeforces.com/contest/1272/problem/A
 * a, b, c のそれぞれの移動を全探索
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        vector<ll> A(3);
        rep(i, 3) {
            cin >> A[i];
        }
        ll ans = INF;
        int x[3] = {1, 0, -1};
        rep(i, 3) {
            rep(j, 3) {
                rep(k, 3) {
                    ll a = A[0] + x[i];
                    ll b = A[1] + x[j];
                    ll c = A[2] + x[k];
                    ans = min(ans, abs(a - b) + abs(b - c) + abs(c - a));
                }
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
