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
 * B. Fridge Lockers
 * https://codeforces.com/contest/1255/problem/B
 *
 * N != M || N == 2 のとき不可
 * それ以外は 0 から N まで循環するように鎖でつないでいく。
 * 各コストはそれぞれ 2 回ずつ必要になる
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N, M;
        cin >> N >> M;
        vector<P> A;
        rep(i, N) {
            ll a;
            cin >> a;
            A.push_back({a, i});
        }
        ll sum = 0;
        vector<P> tar;
        if (N != M || N == 2) {
            cout << -1 << '\n';
            continue;
        }
        rep(i, N) {
            sum += 2 * A[i].first;
            if (i != N - 1) {
                tar.push_back({i, i + 1});
            } else {
                tar.push_back({i, 0});
            }
        }
        cout << sum << '\n';
        rep(i, M) {
            cout << tar[i].first + 1 << " " << tar[i].second + 1 << '\n';
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
