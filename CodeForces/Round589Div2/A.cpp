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
 * A. Distinct Digits
 * https://codeforces.com/contest/1228/problem/A
 * ループで回して文字列に変換して各桁の数字を記録しておく。
 * 全て違うなら出力。制約的に十分間に合う。
 */
void Main() {
    int l, r;
    cin >> l >> r;
    int ans = 0;
    rep2(i, l, r+1) {
        string S = to_string(i);
        unordered_set<int> used;
        rep(j, S.size()) {
            used.insert(S[j]);
        }
        if (S.size() == used.size()) {
            cout << S << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
