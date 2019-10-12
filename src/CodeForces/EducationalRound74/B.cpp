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
 * B. Kill 'Em All
 * https://codeforces.com/contest/1238/problem/B
 *
 * 最も大きい値を持つものを攻撃すればいい。
 * 攻撃対象と攻撃回数を保持しておけば、降順にソートされたものを順にみていくことができる
 */
void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        int n, r;
        cin >> n >> r;
        priority_queue<int> queue;
        rep(i, n) {
            int x;
            cin >> x;
            queue.push(x);
        }

        int cnt = 0;
        set<int> exp;
        while (!queue.empty()) {
            int q = queue.top();
            queue.pop();
            if (exp.find(q) != exp.end()) {
                continue;
            }
            if (q - cnt * r > 0) {
                cnt++;
                exp.insert(q);
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
