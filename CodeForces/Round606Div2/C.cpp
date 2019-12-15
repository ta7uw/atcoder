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
 * C. As Simple as One and Two
 * https://codeforces.com/contest/1277/problem/C
 *
 * twone は o, two は w, one は n を貪欲に削除すれば良い
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        string S;
        cin >> S;
        vector<ll> ans;
        int N = (int) S.size();
        rep(i, N) {
            if (i + 4 < N && S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o'  && S[i + 3] == 'n' && S[i + 4] == 'e') {
                ans.push_back(i + 3);
                S[i + 2] = ' ';
            }
            if (i + 2 < N && S[i] == 't' && S[i + 1] == 'w' && S[i + 2] == 'o') {
                ans.push_back(i + 2);
                S[i + 1] = ' ';
            }
            if (i + 2 < N && S[i] == 'o' && S[i + 1] == 'n' && S[i + 2] == 'e') {
                ans.push_back(i + 2);
                S[i + 1] = ' ';
            }
        }
        cout << ans.size() << '\n';
        rep(i, ans.size()) {
            cout << ans[i] << ' ';
        }
        cout  << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
