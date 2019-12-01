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
 * https://atcoder.jp/contests/abc119/tasks/abc119_c
 *
 * 4^n全探索。再帰全探索で実装。
 * i番目の竹をA, B, Cに使う、使わないの4通りを試す
 * A, B, Cを構築するために少なくとも1つの竹を使う必要があることに注意する。
 * 伸縮による変化は合成を行った最後にやればよい。
 */
int N, A, B, C;
vector<int> L;

int dfs(int a, int b, int c, int now) {
    int res = MOD;
    if (now == N) {
        if (a != 0 && b != 0 && c!=0) {
            return abs(A - a) + abs(B - b) + abs(C - c);
        }
    } else {
        res = min(res, dfs(a + L[now], b, c, now + 1) + (a == 0 ? 0 : 10));
        res = min(res, dfs(a, b + L[now], c, now + 1) + (b == 0 ? 0 : 10));
        res = min(res, dfs(a, b, c + L[now], now + 1) + (c == 0 ? 0 : 10));
        res = min(res, dfs(a, b, c, now + 1));
    }
    return res;
}

void Main() {
    cin >> N >> A >> B >> C;
    L.resize(N, 0);
    rep(i, N) cin >> L[i];
    int ans = dfs(0, 0, 0, 0);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
