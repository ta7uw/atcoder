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
 * C. Labs
 * https://codeforces.com/contest/1236/problem/C
 *  最大値が ⌊ N^2 ⌋  に選べばよい
 *  1 ~ N^2 まで蛇のようにうねりねがら各配列に順に割り当てていくとこれを達成できる
 */
void Main() {
    int N;
    cin >> N;
    vector<vector<int>> ans(N, vector<int>(N, 0));
    int cnt = 1;
    int f = 1;
    rep(i, N) {
        rep(j, N) {
            if (f) {
                ans[i][j] = cnt;
            } else {
                ans[i][N - 1 - j] = cnt;
            }
            cnt++;
        }
        f = 1 - f;
    }
    rep(i, N) {
        rep(j, N) {
            cout << ans[j][i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
