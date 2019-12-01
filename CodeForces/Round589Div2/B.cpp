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

int grid[1010][1010];

/**
 * B. Filling the Grid
 * https://codeforces.com/contest/1228/problem/B
 * 指示通りにシミュレーションを行う。
 * カラムのシミュレーションの際にはレコードの結果を元に実現可能かどうかも確認する。
 * 残ったマスは選ぶ・選ばないの2通りが存在するので
 * 2をマスの個数だけかけたものが答え
 */
void Main() {
    int H, W;
    cin >> H >> W;
    vector<int> R(H);
    vector<int> C(W);

    rep(i, H) cin >> R[i];
    rep(i, W) cin >> C[i];

    rep(i, H) {
        int r = R[i];
        rep(j, min(W, r)) {
            grid[i][j] = 1;
        }
        grid[i][r] = 2;
    }

    rep(j, W) {
        int c = C[j];
        rep(i, min(H, c)) {
            if (grid[i][j] != 2) {
                grid[i][j] = 1;
            }else{
                cout << 0 << '\n';
                return;
            }
        }
        if (grid[c][j] != 1) {
            grid[c][j] = 2;
        }else{
            cout << 0 << '\n';
            return;
        }
    }
    ll ans = 1;
    ll cnt = 0;

    rep(i, H) {
        rep(j, W) {
            if (grid[i][j] == 0) {
                cnt++;
            }
        }
    }
    if (cnt == 0) {
        cout << 1 << '\n';
        return;
    }
    rep(i, cnt) {
        ans *= 2;
        ans %= MOD;
    }
    cout << ans % MOD << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
