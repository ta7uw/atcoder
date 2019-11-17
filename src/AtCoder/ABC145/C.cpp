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
 * C - Average Length
 * https://atcoder.jp/contests/abc145/tasks/abc145_c
 *
 * N <= 8 なので next_permutation を使って順列を全列挙する
 */
void Main() {
    int N;
    cin >> N;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    vector<int> per;
    double div = 1;
    rep(i, N) {
        div *= i + 1;
        per.push_back(i);
    }
    double ans = 0;
    do {
        int p_x = 0;
        int p_y = 0;
        rep(i, N) {
            P p = items[per[i]];
            if (i != 0) {
                ans += pow(pow(abs(p_x - p.first), 2) + pow(abs(p_y - p.second), 2), 0.5);
            }
            p_x = p.first;
            p_y = p.second;
        }
    } while (next_permutation(per.begin(), per.end()));

    cout << ans / div << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
