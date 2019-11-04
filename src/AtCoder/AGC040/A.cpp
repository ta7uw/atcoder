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
 * A - ><
 * https://atcoder.jp/contests/agc040/tasks/agc040_a
 *
 * a の各項について、その値は左に連続する < の個数と右の連続する > の個数の max となるとき
 * 条件を満たす数列が得られる。
 *
 */
void Main() {
    string S;
    cin >> S;
    int N = (int) S.size();

    vector<int> A(N + 1, 0);
    rep(i, N) {
        if (S[i] == '<') {
            A[i + 1] = A[i] + 1;
        }
    }

    rrep(j, N - 1, 0) {
        if (S[j] == '>') {
            A[j] = max(A[j + 1] + 1, A[j]);
        }
    }
    ll ans = accumulate(A.begin(), A.end(), 0LL);
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
