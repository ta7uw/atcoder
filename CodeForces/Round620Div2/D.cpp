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

void Main() {
    ll T;
    cin >> T;
    rep(t, T) {
        ll N;
        string S;
        cin >> N >> S;

        vector<int> min_ans(N);
        ll num = N;
        ll last = 0;
        rep(i, N) {
            if (i == N - 1 || S[i] == '>') {
                rrep(j, i, last) {
                    min_ans[j] = num--;
                }
                last = i + 1;
            }
        }
        vector<int> max_ans(N);
        num = 1;
        last = 0;
        rep(i, N) {
            if (i == N - 1 || S[i] == '<') {
                rrep(j, i, last) {
                    max_ans[j] = num++;
                }
                last = i + 1;
            }
        }

        // output
        rep(i, N) {
            ll a = min_ans[i];
            cout << a << ' ';
        }
        cout << '\n';

        rep(i, N) {
            ll a = max_ans[i];
            cout << a << ' ';
        }
        cout << '\n';
    }

}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
