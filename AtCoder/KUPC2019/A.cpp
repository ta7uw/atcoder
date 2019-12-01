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
 * A - November Festival
 * https://atcoder.jp/contests/kupc2019/tasks/kupc2019_a
 * 各要素において +X した場合に最大値になることができるか判定する。
 * 制約的にこれで間に合う。
 */
void Main() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int ans = 0;
    rep(i, N) {
        int a = A[i];
        A[i] = a + X;
        int max_num = *max_element(A.begin(), A.end());
        if (max_num == a + X) {
            ans ++;
        }
        A[i] = a;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
