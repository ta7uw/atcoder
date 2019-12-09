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
 * C - HonestOrUnkind2
 * https://atcoder.jp/contests/abc147/tasks/abc147_c
 * bit全探索
 * O(N^2 * 2^N) N <= 15 なので間に合う
 */
void Main() {
    int N;
    cin >> N;
    map<int, vector<P>> info;
    rep(i, N) {
        int a;
        cin >> a;
        rep(j, a) {
            int x, y;
            cin >> x >> y;
            x--;
            info[i].push_back({x, y});
        }
    }
    int ans = 0;
    rep(i, 1 << N) {
        int cnt = 0;
        vector<bool> tmp(N, false);
        rep(j, N) {
            if (i & (1 << j)) {
                cnt++;
                tmp[j] = true;
            }
        }
        bool check = true;
        rep(j, N) {
            if (tmp[j]) {
                vector<P> items = info[j];
                for(P p : items) {
                    if (p.second == 1) {
                        if (tmp[p.first]) {
                            continue;
                        }else{
                            check = false;
                        }
                    }else{
                        if (tmp[p.first]) {
                            check = false;
                        }else{
                            continue;
                        }
                    }
                }
            }
        }
        if (check) {
            ans = max(ans, cnt);
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
