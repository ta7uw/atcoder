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
 * A. Integer Points
 * https://codeforces.com/contest/1248/problem/A
 *
 * y = x + p, y = -x + q の交点の座標は ((p-q)/2, (p+q)/2) なのでこれらが整数になるには
 * 偶数と偶数、奇数と奇数のペアになる必要がある。
 * よって p の偶数 p1 , 奇数 p2 と q の偶数 q1 と奇数 q2 を数えて
 * p1 * q1 + p2 * q2 がこたえ
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        vector<int> p_list(N);
        rep(i, N) cin >> p_list[i];
        int M;
        cin >> M;
        vector<int> q_list(M);
        rep(i, M) cin >> q_list[i];
        int ans = 0;

        ll p_e = 0;
        ll p_o = 0;
        rep(i, N) {
            int p = p_list[i];
            if (p % 2 == 0) {
                p_e++;
            } else {
                p_o++;
            }
        }
        ll q_e = 0;
        ll q_o = 0;
        rep(i, M) {
            int q = q_list[i];
            if (q % 2 == 0) {
                q_e++;
            } else {
                q_o++;
            }
        }
        cout << p_e * q_e + p_o * q_o << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
