#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int L, X, Y, S, D;
    cin >> L >> X >> Y >> S >> D;

    if (D >= S) {
        if (Y - X <= 0) {
            double ans = (double) (D - S) / (X + Y);
            cout << ans << endl;
        } else {
            double ans = min((double) (D - S) / (Y + X), (double) (L - D + S) / (Y - X));
            cout << ans << endl;
        }
    } else {
        if (Y - X <= 0) {
            double ans = (double) (L - S + D) / (X + Y);
            cout << ans << endl;
        } else {
            double ans = min((double) (L - S + D) / (Y + X), (double) (S - D) / (Y - X));
            cout << ans << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
