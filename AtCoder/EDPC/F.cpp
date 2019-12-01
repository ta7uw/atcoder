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

ll dp[3005][3005];

void Main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    rep(i, N) {
        rep(j, M) {
            if (S[i] == T[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    string ans = "";
    int s = N - 1;
    int t = M - 1;
    while ((s >= 0 && t >= 0) && ans.size() < dp[N][M]) {
        if (S[s] == T[t]) {
            ans += S[s];
            s--;
            t--;
        } else {
            if (s > 0 && t > 0) {
                if (dp[s+1][t] > dp[s][t+1]) {
                    t--;
                } else {
                    s--;
                }
            } else {
                if (s == 0) {
                    t--;
                } else {
                    s--;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
