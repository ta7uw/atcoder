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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

/**
 * D - Semi Common Multiple
 * https://atcoder.jp/contests/abc150/tasks/abc150_d
 * ai / 2 の lcm を X とすると M 以下の X の奇数倍が条件を満たす
 * X = (ai / 2) * (2*p + 1) より x / (a / 2) は奇数でなければならない
 */
void Main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    ll x = 1;
    ll ans = 0;
    rep(i, N) {
        ll a = A[i];
        a /= 2;
        x = lcm(x, a);
    }
    ll ok2 = true;
    rep(i, N) {
        ll a = A[i];
        a /= 2;
        if ((x / a) % 2 == 0) {
            ok2 = false;
        }
    }
    if (x <= M && ok2) {
        M -= x;
        ans++;
        ans += M / (2 * x);
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
