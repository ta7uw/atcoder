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
 * B. Verse For Santa
 * https://codeforces.com/contest/1279/problem/B
 *
 * 累積和 + 二分探索で ai を抜いたときの最も多いプレゼントの量をもとめる
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N, S;
        cin >> N >> S;
        vector<ll> A(N), B(N + 1, 0);
        rep(i, N) cin >> A[i];
        rep(i, N) B[i + 1] += B[i] + A[i];
        ll M2 = 0;
        rep(i, N) {
            ll b = B[i + 1];
            if (b <= S) {
                M2 = i + 1;
            }
        }
        ll ans = 0;
        ll M = 0;
        //print(B);
        rep(i, N) {
            ll tmp = A[i] + S;
            tmp++;
            ll idx = lower_bound(B.begin(), B.end(), tmp) - B.begin();
            idx -= 2;
            //print(tmp, idx);
            // if (idx - 1 <= i) break;
            if (B[i] <= S && idx > M) {
                ans = i + 1;
                M = idx;
            }
        }
        //print(M, M2);
        if (M2 >= M) {
            cout << 0 << '\n';
        } else {
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
