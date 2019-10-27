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
 * B2. TV Subscriptions (Hard Version)
 * https://codeforces.com/contest/1247/problem/B2
 *
 * B1の方法では制約的に厳しい。
 * しゃくとり法のようにスライドさせてながら含まれる show とその数を map で保持していくと
 * O (N logD) で達成できる
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int N, K, D;
        cin >> N >> K >> D;
        vector<int> A(N, 0);
        rep(i, N) cin >> A[i];
        int ans = MOD;

        map<int, int> show;
        rep(j, D) {
            show[A[j]]++;
        }
        ans = min(ans, (int) show.size());
        rep2(i, D, N) {
            int a = A[i - D];
            int b = A[i];
            show[a]--;
            show[b]++;
            if (show[a] == 0) {
                show.erase(a);
            }
            ans = min(ans, (int) show.size());
        }

        cout << ans << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
