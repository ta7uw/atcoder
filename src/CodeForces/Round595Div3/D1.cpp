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
 * D1. Too Many Segments (easy version)
 * https://codeforces.com/contest/1249/problem/D1
 *
 * imos法を使って各点を含んでいる区間の個数を管理する。
 * K より多く区間がある場合は被っている区間のうち r が最大のものを貪欲に削除していく
 */
void Main() {
    int N, K;
    cin >> N >> K;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;

    vector<int> x(210, 0);
    rep(i, N) {
        P p = items[i];
        x[p.first]++;
        x[p.second + 1]--;
    }
    rep(i, 205) {
        x[i + 1] += x[i];
    }
    vector<int> ans;
    set<int> used;
    rep2(i, 1, 205) {
        int cnt = x[i];
        if (cnt <= K) {
            continue;
        } else {
            while (cnt > K) {
                int num = -1;
                int idx = 0;
                P p;
                rep(j, N) {
                    P p2 = items[j];
                    if (used.find(j) == used.end() && p2.first <= i && p2.second > num) {
                        num = p2.second;
                        p = p2;
                        idx = j;
                    }

                }
                ans.push_back(idx);
                used.insert(idx);
                rep2(k, p.first, p.second + 1) {
                    x[k]--;
                }
                cnt = x[i];
            }
        }
    }
    cout << ans.size() << '\n';
    rep(i, ans.size()) {
        cout << ans[i] + 1 << ' ';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
