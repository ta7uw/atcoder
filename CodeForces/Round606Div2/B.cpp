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
 * B. Make Them Odd
 * https://codeforces.com/contest/1277/problem/B
 *
 * 2 で割れる回数を数えて、残った奇数を key にして map で回数を保持する
 * 各奇数で最も大きい回数をカウントしていく
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N;
        cin >> N;
        vector<ll> A(N);
        rep(i, N) cin >> A[i];
        map<ll, vector<ll>> cnt;
        rep(i, N) {
            ll a = A[i];
            if (a % 2 == 0) {
                ll tmp = a;
                ll c = 0;
                while (tmp % 2 == 0) {
                    tmp /= 2;
                    c++;
                }
                cnt[tmp].push_back(c);
            }
        }
        ll ans = 0;
        for (auto X: cnt ) {
//            print(X.first);
//            print(X.second);
            ll m = *max_element(X.second.begin(), X.second.end());
            ans += m;
        }
        cout << ans << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
