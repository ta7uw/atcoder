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
 * D1. The World Is Just a Programming Task (Easy Version)
 * https://codeforces.com/contest/1248/problem/D1
 *
 * 括弧の合計はゼロでないとならない。beauty string は括弧の最小値の個数と同じ。
 * For example, for string )(()))()((, the array of prefix balances
 * is [-1, 0, 1, 0, -1, -2, -1, -2, -1, 0], and the number of cyclic shifts, 2 – the number of minimums in it (−2).
 * O (N ^ 3) で全ての swap に対する括弧の累積和をだせるのでこれで答えが求まる
 */
void Main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<pair<string, P>> T;
    set<string> used;
    rep(i, N) {
        rep2(j, i, N) {
            string t = S;
            if (t[i] == '(') {
                t[i] = ')';
            } else {
                t[i] = '(';
            }
            if (t[j] == '(') {
                t[j] = ')';
            } else {
                t[j] = '(';
            }
            if (used.find(t) == used.end()) {
                T.push_back({t, {i, j}});
                used.insert(t);
            }
        }
    }
    int ans = -1;
    P p;
    rep(i, T.size()) {
        string t = T[i].first;
        vector<int> acc(t.size() + 1, 0);
        int cnt = 0;
        rep(j, t.size()) {
            if (t[j] == '(') {
                acc[j + 1] = acc[j] + 1;
            } else {
                acc[j + 1] = acc[j] - 1;
            }
        }
        if (acc[t.size()] == 0) {
            int min_num = *min_element(acc.begin(), acc.end());
            if (min_num == 0) cnt--;
            rep(j, t.size() + 1) {
                if (min_num == acc[j]) {
                    cnt++;
                }
            }
            if (cnt >= ans) {
                ans = cnt;
                p = T[i].second;
            }
        }
    }
    if (ans == -1) {
        cout << 0 << '\n';
        cout << 1 << " " << 1 << '\n';
    } else {
        cout << ans << '\n';
        cout << p.first + 1 << " " << p.second + 1 << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
