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
 * A. Stones
 * https://codeforces.com/contest/1236/problem/A
 * どちらの操作を行っても3つの石が取得できる。
 * できるだけ1と2の操作の合計を多くすればいいとわかる
 * 操作c から石を取る方法は2つ目の操作しかないので2つ目の操作から行えばよい。
 * そのあと, 1つ目の操作を可能な限り行う。
 */
void Main() {
    int T;
    cin >> T;
    rep(t,T) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 0;
        int x = min(c/2, b);
        ans += 3 * x;
        b -= x;
        x = min(b/2, a);
        ans += 3 * x;
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
