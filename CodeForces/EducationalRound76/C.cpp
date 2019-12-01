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
 * C. Dominated Subarray
 * https://codeforces.com/contest/1257/problem/C
 *
 * 値とインデックスを保持してソートする。
 * 各値に置いてインデックスの差の最小値が答え
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int n;
        cin >> n;
        vector<P> A;
        rep(i, n) {
            ll a;
            cin >> a;
            A.push_back({a, i});
        }
        sort(A.begin(), A.end());
        if (A.size() >= 2) {
            int ans = MOD;

            ll prev = -1;
            ll prev_v = -1;
            rep(i, n) {
                P p = A[i];
                if (p.first == prev) {
                    ans = min(ans, (int) abs(p.second - prev_v) + 1);
                }
                prev = p.first;
                prev_v = p.second;
            }
            if (ans == MOD) {
                cout << -1 << '\n';
            } else {
                cout << ans << '\n';
            }
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
