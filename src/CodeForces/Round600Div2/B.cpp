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
 * B. Silly Mistake
 * https://codeforces.com/contest/1253/problem/B
 *
 * 入退出情報を map で管理して、退出した人を取り除く。
 * すでに退出した人は別で set で管理して２度目の入室を防ぐ。
 * map が空になったタイミングでその日を終了する。
 */
void Main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    vector<int> ans;
    map<int, int> entered;
    set<int> found;
    int cnt = 0;
    rep(i, N) {
        int a = A[i];
        if (a > 0) {
            if (entered.find(a) != entered.end()) {
                cout << -1 << '\n';
                return;;
            } else {
                if (found.find(a) != found.end()) {
                    cout << -1 << '\n';
                    return;
                }
                entered[a] = 1;
            }
        } else {
            if (entered.find(-a) != entered.end()) {
                entered.erase(-a);
                found.insert(-a);
            } else {
                cout << -1 << '\n';
                return;
            }
        }
        if (entered.empty()) {
            ans.push_back((i + 1) - cnt);
            cnt += ans[ans.size() - 1];
            found.clear();
        }
    }
    if (!entered.empty()) {
        cout << -1 << '\n';
        return;
    }

    cout << ans.size() << '\n';
    rep(i, ans.size()) {
        cout << ans[i] << ' ';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
