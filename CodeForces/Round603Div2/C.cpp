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
 * 計算量: O(√N)
 * 自然数 N の商の種類数を返す。
 * ⌊N/i⌋ = k となる最左の i を l , 最右の i を r とすると [l, r] で  N / i のあまりは等差数列になる。
 * @param N 自然数 N
 * @return x <= i <= y を満たす整数の商 ⌊N/i⌋ が z であるとき, {{x, y}, z} と表す。x の昇順で返す
 */
vector<pair<P, ll>> quotient_range(ll N) {
    ll M;
    vector<pair<P, ll> > res;
    for (M = 1; M * M <= N; M++) {
        res.emplace_back(make_pair(M, M), N / M);
    }
    for (ll i = M; i >= 1; i--) {
        ll L = N / (i + 1) + 1;
        ll R = N / i;
        if (L <= R && res.back().first.second < L) res.emplace_back(make_pair(L, R), N / L);
    }
    return res;
}


/**
 * C. Everyone is a Winner!
 * https://codeforces.com/contest/1263/problem/C
 * 自然数 N の商の種類数を求める。
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N;
        cin >> N;
        auto X = quotient_range(N);
        set<ll> used;
        used.insert(0);
        for (auto x : X) {
            used.insert(x.second);
        }
        cout << used.size() << '\n';
        vector<ll> ans;
        for (auto x : used) {
            ans.push_back(x);
        }
        sort(ans.begin(), ans.end());
        rep(j, ans.size()) {
            cout << ans[j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
