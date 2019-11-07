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
 * A. Payment Without Change
 * https://codeforces.com/contest/1256/problem/A
 *
 * a 枚までで n 円で払えるだけ払ってその後 1 円を b 枚までつかって S 円払うことができるか判定する
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        ll a, b, n, S;
        cin >> a >> b >> n >> S;
        if (S / n > a) {
            S -= n * a;
        }else{
            S = S % n;
        }
        if (S <= b) {
            cout << "YES" << '\n';
        }else{
            cout << "NO" << '\n';
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
