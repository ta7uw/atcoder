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
 * D - Digit Sum Replace
 * https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d
 *
 * 操作をどのように行っても最終的に開かれる予選の回数は同じになる。
 * 操作は以下の 2 パターンに分けられる
 * - 合計が 9 以下となる連続する 2 つの桁を選ぶと、桁数は 1 減り、各桁の数字の和はそのまま
 * - 合計が 10 以上となる連続する 2 つの桁を選ぶと、桁数はそのまま、各桁の数字の和は 9 減る
 * つまり、N の桁数を D 、各桁の数字の和を S とすると
 * - 桁数は 1 で終わるので、パターン #1 はちょうど D - 1 回行われる
 * - 各桁の数字の和は 1 ~ 9 のどれかでおわるので、パターン #2 はちょうど (S - 1) / 9 回行われる。
 * よって答えは (S -1) / 9 + D - 1 となる
 */
void Main() {
    ll M;
    cin >> M;
    vector<P> items(M);
    rep(i, M) cin >> items[i].first >> items[i].second;
    ll d_sum = 0;
    ll d_cnt = 0;
    rep(i, M) {
        ll d = items[i].first;
        ll c = items[i].second;
        d_sum += d * c;
        d_cnt += c;
    }
    cout << (d_sum - 1) / 9 + d_cnt - 1 << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
