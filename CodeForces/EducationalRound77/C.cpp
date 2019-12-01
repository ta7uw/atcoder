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
    gcd(b, a % b);
}

/**
 * C. Infinite Fence
 * https://codeforces.com/contest/1260/problem/C
 * b >= r とする。
 * - gcd(r, b) == 1 のとき (x, x + b) 内に r が k 個存在するか
 * - gcd(r, b) > 1 のとき r, b を gcd(r, b) で割ると上記と同じように判定できる
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll r, b, k;
        cin >> r >> b >> k;
        ll g = gcd(r, b);
        r = r / g;
        b = b / g;
        if (r > b) swap(r, b);
        if (b - 1 <= (k - 1) * r) {
            cout << "OBEY" << '\n';
        }else{
            cout << "REBEL" << '\n';
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
