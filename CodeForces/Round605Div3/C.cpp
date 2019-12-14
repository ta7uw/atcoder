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
 * C. Yet Another Broken Keyboard
 * https://codeforces.com/contest/1272/problem/C
 * 使用可能な文字列の部分文字列を数える
 */
void Main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<char> A(K);
    rep(i, K) cin >> A[i];
    set<char> used;
    rep(i, K) {
        char s = A[i];
        used.insert(s);
    }
    ll cnt = 0;
    ll ans = 0;
    rep(i, N) {
        char s = S[i];
        if (used.find(s) != used.end()) {
            cnt++;
        } else {
            ans += (cnt + 1) * cnt / 2;
            cnt = 0;
        }
    }
    ans += (cnt + 1) * cnt / 2;
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
