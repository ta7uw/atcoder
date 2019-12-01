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
 * A - Connection and Disconnection
 * https://atcoder.jp/contests/agc039/tasks/agc039_a
 * - 全ての文字が同じ場合
 * - S[0] != S[N-1]
 * - S[0] == S[N-1] かつ　最後の文字を変更しなければならない場合
 * - S[0] == S[N-1] かつ　最後の文字を変更しなくてもいい場合
 * 以上4パターンの場合分け
 */
void Main() {
    string S;
    ll K;
    cin >> S;
    cin >> K;
    ll N = S.size();
    unordered_set<ll> set;
    rep(i, N) {
        set.insert(S[i] - 'a');
    }
    if (set.size() == 1) {
        cout << (ll) N * K / 2 << '\n';
    } else {
        string T = S;
        ll cnt = 0;
        rep2(i, 1, N) {
            if (T[i] == T[i - 1]) {
                cnt++;
                T[i] = '1';
            }
        }
        if (S[0] == S[N - 1] && T[N - 1] != '1') {
            ll cnt2 = 1;
            S[0] = '1';
            rep2(i, 1, N) {
                if (S[i] == S[i - 1]) {
                    cnt2++;
                    S[i] = '1';
                }
            }
            cout << (ll) cnt + (ll) cnt2 * (K - 1) << '\n';
        } else {
            cout << (ll) cnt * K << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
