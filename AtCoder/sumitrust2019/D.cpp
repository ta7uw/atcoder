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
 * D - Lucky PIN
 * https://atcoder.jp/contests/sumitrust2019/submissions/8842354
 *
 * 暗証番号 V を 000 から 999 まで決め打ちする。
 * S から貪欲に V が作れるか判定する。
 * 制約的に貪欲が間に合わないのであれば二分探索が使える
 *
 */
void Main() {
    int N;
    string S;
    cin >> N >> S;
    unordered_set<string> ans;
    rep(i, 10) {
        rep(j, 10) {
            rep(k, 10) {
                string a = to_string(i) + to_string(j) + to_string(k);
                ll target[3] = {i, j, k};
                int tar = 0;
                rep(x, N) {
                    if (S[x] - '0' == target[tar]) tar++;
                    if (tar == 3) {
                        break;
                    }
                }
                if (tar == 3) ans.insert(a);
            }
        }
    }
    cout << ans.size() << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
