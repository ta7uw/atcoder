
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<(n);i++)
#define rep2(i, m, n) for(int i=m;i<(n);i++)
#define rrep(i, n, m) for(int i=n;i>=(m);i--)
using Graph = vector <vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1000000000000000000L;
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int Q;
    cin >> Q;
    rep(i, Q) {
        ll N, M;
        cin >> N >> M;

        vector <ll> target(10);
        ll tmp = M;
        ll ans = 0;
        rep(j, 10) {
            target[j] = tmp % 10;
            tmp += M;
        }

        ll cnt = N / (10 * M);
        ans += accumulate(target.begin(), target.end(), 0L) * cnt;
        if (N >= M) {
            ll cnt2 = (N % (10 * M)) / M;
            rep(j, cnt2) {
                ans += target[j];
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
