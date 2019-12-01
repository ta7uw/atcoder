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
 * B. PIN Codes
 * https://codeforces.com/contest/1263/problem/B
 *
 * 以前に出現したことのあるPINが出現したら、1桁ずらして得られるPINを探索する
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        vector<string> P(N);
        rep(i, N) cin >> P[i];
        vector<string> ans;
        int cnt = 0;
        rep(i, N) {
            string p = P[i];
            if (find(ans.begin(), ans.end(), p) != ans.end()) {
                bool found = false;
                rep(j, 4) {
                    int now = p[j] - '0';
                    rep(x, 10) {
                        if (x == now) continue;
                        char pr = p[j];
                        p[j] = char(x + '0');
                        if (find(ans.begin(), ans.end(), p) == ans.end() && find(P.begin(), P.end(), p) == P.end()) {
                            ans.push_back(p);
                            cnt++;
                            found = true;
                            break;
                        }else{
                            p[j] = pr;
                        }
                    }
                    if (found) break;
                }
            } else {
                ans.push_back(p);
            }
        }
        cout << cnt << '\n';
        rep(i, N) {
            cout << ans[i] << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
