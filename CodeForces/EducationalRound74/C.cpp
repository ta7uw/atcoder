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
 * C. Standard Free2play
 * https://codeforces.com/contest/1238/problem/C
 * 難読
 * 1 ~ h までの足場がある。最小は n 個の足場しか出現していないが
 * x でレバーを引くとxとx-1の出現状況がそれぞれ反転する
 * この事象とクリスタルをうまく使って 0 地点までたどり着くのをシミュレーション
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int H, N;
        cin >> H >> N;
        vector<int> P(N);
        rep(i, N) cin >> P[i];
        P.push_back(-10);
        int ans = 0;
        int h = H;
        int idx = 1;
        while (h >= 3) {
            if (P[idx] < h - 1) {
                h = P[idx] + 1;
            } else {
                if (P[idx + 1] == h - 2) {
                    h -= 2;
                    idx += 2;
                    continue;
                }else {
                    h -= 2;
                    idx += 1;
                    ans++;
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
