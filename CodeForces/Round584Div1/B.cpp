#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using P = pair<ll, ll>;
using edge = pair<ll, P>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
using Graph = vector<vector<ll>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const ll INF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;

    int ans = -1;
    rep(t, 10000) {
        int cnt = 0;
        rep(i, N) {
            P p = items[i];
            int s = S[i] - '0';
            if (t >= p.second) {
                int ss = t - p.second;
                s = 1 - s;
                if ((ss / p.first) % 2 != 0) {
                    s = 1 - s;
                }
            }
            if (s == 1) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
