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
 * B. Grow The Tree
 * https://codeforces.com/contest/1248/problem/B
 *
 * 縦の長さが a 横の長さが b の長方形を考える
 * a^2 + b^2 を最大化するためにはどちらか一方をできるだけ大きくする
 * ソートして前半は a , 後半は b とすると a^2 + b^2 が最大化できる
 * N / 2 が前半であることに注意
 */
void Main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    sort(A.begin(), A.end());
    ll f = 0;
    ll s = 0;
    rep(i, N/2) {
        f += A[i];
    }
    rep2(i, N/2, N) {
        s += A[i];
    }
    cout << f * f + s * s << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
