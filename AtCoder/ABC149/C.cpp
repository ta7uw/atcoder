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

bool is_prime(ll N) {
    if (N <= 1) {
        return false;
    } else {
        for (ll i = 2; i * i <= N; ++i) {
            if (N % i == 0) {
                return false;
            }
        }
    }
    return true;
}


/**
 * C - Next Prime
 * https://atcoder.jp/contests/abc149/tasks/abc149_c
 * X 以上の数が素数かどうか順に探していく
 */
void Main() {
    ll X;
    cin >> X;
    rep2(i, X, X*100) {
        if (is_prime(i)) {
            cout << i << '\n';
            return;
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
