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
 * B1. TV Subscriptions (Easy Version)
 * https://codeforces.com/contest/1247/problem/B1
 *
 * D日連続で見る show の種類を最小化したい。
 * a1, a2 ... an のうち D ずつのずらした区間に含まれる show の種類の最小値を求める。
 * 制約的に愚直にループで間に合う
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int N, K, D;
        cin >> N >> K >> D;
        vector<int> A(N, 0);
        rep(i, N) cin >> A[i];

        int ans = MOD;
        rep(i, N) {
            set<int> show;
            int cnt = 0;
            rep2(j, i, min(i + D, (ll) N)) {
                show.insert(A[j]);
                cnt++;
            }
            if (cnt == D) {
                ans = min(ans, (int) show.size());
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
