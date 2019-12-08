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

bool dp[30005][4][1000];


/**
 * D - Lucky PIN
 * https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d
 *
 * DP 解
 * dp[i][j][k] i 番目まで見た時に j 桁の数字 k をつくることができるか。
 * dp[0][0][0] = true として dp[i][j][k] が true のときに
 * dp[i + 1][j + 1][k * 10 * num] と dp[i + 1][j][k] へ遷移する。
 * dp[N][3][k] == true  (0 <= k < 1000) の個数が答え
 */
void Main() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    dp[0][0][0] = true;
    rep(i, N) {
        int num = S[i] - '0';
        rep(j, 4) {
            rep(k, 1000) {
                if (dp[i][j][k]) {
                    if (j != 3 && 10 * k + num < 1000) {
                        dp[i + 1][j + 1][10 * k + num] = true;
                    }
                    dp[i + 1][j][k] = true;
                }
            }
        }
    }
    int cnt = 0;
    rep(i, 1000) {
        if (dp[N][3][i]) cnt++;
    }
    cout << cnt << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
