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
 * D. Remove One Element
 * https://codeforces.com/contest/1272/problem/D
 * 前から見て i までの連続増加列長さ ( cnt[i] )と後ろから見て i までの連続減少列の長さ ( cnt2[i] )をあらかじめもとめておき、
 * 各 i について cnt[i - 1] + cnt2[i + 1] の max をとればよい
 */
void Main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N) cin >> A[i];
    vector<ll> cnt(N, 0);
    ll ans = 0;
    rep(i, N) {
        if (i == 0) {
            cnt[i] = 1;
        } else {
            if (A[i] > A[i - 1]) cnt[i] = cnt[i - 1] + 1;
            else cnt[i] = 1;
        }
        ans = max(ans, cnt[i]);
    }
    vector<ll> cnt2(N, 0);
    rrep(i, N - 1, 0) {
        if (i == N - 1) cnt2[i] = 1;
        else {
            if (A[i] < A[i + 1]) {
                cnt2[i] = cnt2[i + 1] + 1;
            } else {
                cnt2[i] = 1;
            }
        }
    }
    rep2(i, 1, N - 1) {
        if (A[i - 1] < A[i + 1]) {
            ans = max(ans, cnt[i - 1] + cnt2[i + 1]);
        }
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
