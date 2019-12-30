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

bool check[100005];

/**
 * D - Prediction and Restriction
 * https://atcoder.jp/contests/abc149/tasks/abc149_d
 *
 * 同じ手で勝った場合に得られる点数は同じなので貪欲に勝っていけば良い。
 * K 回目前に同じ手をだしている場合は負けを選ぶ
 */
void Main() {
    ll N, K, R, S, P;
    cin >> N >> K >> R >> S >> P;
    string T;
    cin >> T;
    ll ans = 0;
    rep(i, N) {
        if (i - K >= 0 && T[i] == T[i-K] && check[i - K]) {
            check[i] = false;
        } else {
            if (T[i] == 'r') {
                ans += P;
                check[i] = true;
            } else if (T[i] == 's') {
                ans += R;
            } else {
                ans += S;
            }
            check[i] = true;
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
