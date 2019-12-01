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
 * E - Get Everything
 * https://atcoder.jp/contests/abc142/tasks/abc142_e
 * ビットDP (bitDP) もらうDP実装
 * 0 以上 2
 * N 未満の整数 j が,「1 以上 N 以下の整数 k について, 現在購入している鍵で宝箱 k を開けら
 * れることと,j を 2 進数表記した際に k − 1 桁目が 1 であることが同値」という状態を表すこととします.
 */
void Main() {
    int N, M;
    cin >> N >> M;
    vector<P> keys;
    rep(i, M) {
        int a, b;
        cin >> a >> b;
        int s = 0;
        rep(j, b) {
            int c;
            cin >> c;
            c--;
            s |= 1 << c;
        }
        keys.emplace_back(s, a);
    }
    vector<ll> dp(1 << N, INF);
    dp[0] = 0;
    rep(s, 1 << N) {
        rep(i, M) {
            ll t = s | keys[i].first;
            ll cost = dp[s] + keys[i].second;
            dp[t] = min(dp[t], cost);
        }
    }
    ll ans = dp.back();
    if (ans == INF) {
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
