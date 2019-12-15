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

vector<string> ans;

void dfs(int x, string s, string t) {
    if (x >= 11) return;
    if (s != "") {
        ans.push_back(s);
    }
    dfs(x + 1, s + t, t);
}

/**
 * A. Happy Birthday, Polycarp!
 * https://codeforces.com/contest/1277/problem/A
 *
 * 1 ~ 9 各数字が連続する値を全列挙してから N 以下のものを数える
 */
void Main() {
    int T;
    cin >> T;
    rep2(i, 1, 10) {
        dfs(0, "", to_string(i));
    }
    rep(t, T) {
        ll N;
        cin >> N;
        ll cnt = 0;
        for (string s : ans) {
            ll x = stoll(s);
            if (x <= N) {
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
