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
 * C. p-binary
 * https://codeforces.com/contest/1247/problem/C
 *
 * 答えを cnt 回に決め打つと、二冪をちょうど cnt 個使って N - p * cnt をつくる問題になる
 * - p >= 0 で N - p * cnt < 0 は達成不可
 * - popcount(N - p * cnt ) <= cnt <= N - p * cnt  ならok
 *  二冪 b は b / 2, b/ 2 へ分解できるので　N - p * cnt　まで増やすことは可能
 *  popcount(x) は x のうち立っているビットの数を返す。また x を二冪の和で表すときの項数の最小値
 */

ll N, p;

bool f(int cnt) {
    ll x = N - p * cnt;
    if (p >= 0 && x < 0) {
        return false;
    }
    auto s = bitset<60>(x);
    string S = s.to_string();
    int bit_cnt = 0;
    rep(i, (int) S.size()) {
        if (S[i] == '1') {
            bit_cnt ++;
        }
    }
    return bit_cnt <= cnt && cnt <= x;
}

void Main() {
    cin >> N >> p;
    rep(i, 100) {
        if (f(i)) {
            cout << i << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
