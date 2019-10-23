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
 * B1. Books Exchange (easy version)
 * https://codeforces.com/contest/1249/problem/B1
 *
 * 問題文の指示通り愚直にシミュレーション
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int N;
        cin >> N;
        vector<int> P(N);
        rep(i, N) cin >> P[i];
        vector<int> ans(N, 0);
        rep(i, N) {
            int p = P[i];
            int a = 1;
            while (p != i + 1) {
                a ++;
                p = P[p-1];
            }
            ans[i] = a;
        }
        rep(i, N) {
            cout << ans[i] << ' ';
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
