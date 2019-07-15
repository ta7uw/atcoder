#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#ifdef __DEBUG
#include "cpp-pyprint/pyprint.h"
#endif

void Main() {
    ll L, R;
    cin >> L >> R;
    long long ans = MOD;
    if (R - L + 1 >= 2019) {
        cout << 0 << endl;
    }else{
        for (ll i = L; i <= R; ++i) {
            for (ll j = L; j <= R; ++j) {
                if (i == j) {
                    continue;
                }else{
                    ans = min(ans, i * j % 2019);
                }
            }
        }
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
