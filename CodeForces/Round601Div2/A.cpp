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
 * A. Changing Volume
 * https://codeforces.com/contest/1255/problem/A
 *
 * 5, 2, 1 の順に変化させられるだけ変化させていく
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int a, b;
        cin >> a >>  b;
        int tmp = abs(a - b);
        int cnt = tmp / 5;
        tmp -= 5 * cnt;
        int cnt2 = tmp / 2;
        tmp -= 2 * cnt2;
        cout << tmp + cnt + cnt2 << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
