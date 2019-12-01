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
 * B. Rooms and Staircases
 * https://codeforces.com/contest/1244/problem/B
 *
 * 階段が1つもなければ N
 * 存在すれば、最も左か最も右のどちらかの階段を使って 左から入って左からでる右から入って右にでるムーブをする
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        string S;
        cin >> S;
        if (S[0] == '1' || S[N - 1] == '1') {
            cout << 2 * N << '\n';
        } else {
            ll ans = -1;
            rep(i, N) {
                if (S[i] == '1') {
                    ans = max(ans, (i + 1));
                    ans = max(ans, N - i);
                }
            }
            if (ans == -1) {
                cout << N << '\n';
            } else {
                cout << ans * 2 << '\n';
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
