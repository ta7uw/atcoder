#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using Graph = vector <vector<ll>>;
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
 * B. Snow Walking Robot
 * https://codeforces.com/contest/1272/problem/B
 *
 * 答えが LR, UD しか存在しない場合を除けば D, R, U, L の順に移動すれば
 * min(cnt(L), cnt(R)), min(cnt(U), cnt(D)) だけ左右、上下に移動できる
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        string S;
        cin >> S;
        ll r = 0;
        ll l = 0;
        ll u = 0;
        ll d = 0;
        rep(i, S.size()) {
            if (S[i] == 'R') r++;
            if (S[i] == 'L') l++;
            if (S[i] == 'U') u++;
            if (S[i] == 'D') d++;
        }
        string ans = "";
        ll yoko = min(r, l);
        ll tate = min(u, d);
        ll r_cnt = 0;
        ll l_cnt = 0;
        ll u_cnt = 0;
        ll d_cnt = 0;
        rep(i, S.size()) {
            if (S[i] == 'R') {
                if (r_cnt < yoko) {
                    r_cnt++;
                    ans += S[i];
                }
            }
            if (S[i] == 'L') {
                if (l_cnt < yoko) {
                    l_cnt++;
                    ans += "Z";
                }
            }
            if (S[i] == 'U') {
                if (u_cnt < tate) {
                    u_cnt++;
                    ans += S[i];
                }
            }
            if (S[i] == 'D') {
                if (d_cnt < tate) {
                    d_cnt++;
                    ans += S[i];
                }
            }
        }
        sort(ans.begin(), ans.end());
        if (tate == 0 && yoko >= 2) {
            ans = "LR";
        }
        if (yoko == 0 && tate >= 2) {
            ans = "UD";
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
            if (ans[i] == 'Z') {
                cout << "L";
            } else {
                cout << ans[i];
            }
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
