#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define rrep(i, n, m) for(int i=n;i>=(m);i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif


ll dp[100005][13];

void Main() {
    string S;
    cin >> S;

    dp[0][0] = 1;
    for (int i = 0; i < S.length(); ++i) {
        if (S[i] == '?') {
            for (int j = 0; j < 10; ++j) {
                for (int k = 0; k < 13; ++k) {
                    dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
                    dp[i + 1][(k * 10 + j) % 13] %= MOD;
                }
            }
        } else {
            int j = S[i] - '0';
            for (int k = 0; k < 13; ++k) {
                dp[i + 1][(k * 10 + j) % 13] += dp[i][k];
                dp[i + 1][(k * 10 + j) % 13] %= MOD;
            }
        }
    }
    cout << dp[S.length()][5] % MOD << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
