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
 * C. Platforms Jumping
 * https://codeforces.com/contest/1256/problem/C
 *
 * 最初は板を左端から詰めていき足場をつくる。
 * ゴールからスタートに戻れれるかを考える。
 * ゴールから飛べるところまで飛ぶようにして板をずらしていき、板がなくなる前にスタートに到達できれば YES を出力
 */
void Main() {
    int N, M, D;
    cin >> N >> M >> D;
    vector<int> C(M);
    rep(i, M) cin >> C[i];
    int pos = 0;
    vector<int> ans;
    rep(i, M) {
        int c = C[i];
        rep(j, c) {
            ans.push_back(i + 1);
        }
    }
    int last = (int) ans.size() - 1;
    int length = N - (int) ans.size() + 1;
    ans.resize(N, 0);

    pos = N;
    int rem = M - 1;
    while (length > D) {
        int move = length - D;
        int c = C[rem];
        if (rem < 0) {
            cout << "NO" << '\n';
            return;
        }
        rep(i, c) {
            if (last - i >= 0) {
                ans[last - i] = 0;
            }
        }
        rep(i, c) {
            if (pos - D - i >= 0) {
                ans[pos - D - i] = rem + 1;
            }
        }
        length -= (D-1);
        pos -= (D + c - 1);
        rem --;
        last -= c;
    }
    cout << "YES" << '\n';
    rep(i, N) {
        cout << ans[i] << ' ';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
