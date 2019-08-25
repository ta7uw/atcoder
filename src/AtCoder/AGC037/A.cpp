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

int dp[200005][2];

void Main() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    if (s[0] == s[1]) {
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[1][0] = 1;
        dp[1][1] = 1;
    } else {
        dp[0][0] = 1;
        dp[0][1] = 0;
        dp[1][0] = 2;
        dp[1][1] = 1;
    }

    rep2(i, 2, n){
        if(s[i-1] == s[i]){
            dp[i][0] = dp[i-1][1] + 1;
            dp[i][1] = dp[i-2][0] + 1;
        }else{
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-2][0] + 1;
        }
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
