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
 * D. Binary String Minimizing
 * https://codeforces.com/contest/1256/problem/D
 *
 * 先頭からこれまでに出現した 1 を数えておき、0 を貪欲に 1 より前にもってくるようにする。
 * 0 が出現するたびこれまでに出現した 1 の数を K から引いていき、すべての 1 より前に移動する。
 * K が足りず全ての 1 より前には移動できなかった場合は、できるところまで移動する
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        ll N, K;
        cin >> N >> K;
        string S;
        cin >> S;

        int sum_one = 0;
        int cnt = 0;
        int last = -1;
        rep(i, N) {
            if (S[i] == '1') {
                sum_one++;
            }else{
                if (K - sum_one >= 0) {
                    cnt ++;
                    K -= sum_one;
                }else{
                    if (last == -1){
                        last = i;
                    }
                }
            }
        }
        string ans = "";
        rep(i, cnt) {
            ans += '0';
        }
        int cnt2 = cnt;
        rep(i, N) {
            if (S[i] == '0' && cnt2 >= 1) {
                cnt2 --;
            }else{
                ans += S[i];
            }
        }
        if (last != -1) {
            int m = -1;
            rrep(i, last-1,0) {
                if (ans[i] == '1' && abs(last-i) <= K) {
                    m = i;
                }
            }
            if (m != -1) {
                ans[last] = '1';
                ans[m] = '0';
            }
        }

        cout << ans<< '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
