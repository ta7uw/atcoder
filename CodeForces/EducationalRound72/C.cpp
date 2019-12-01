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

void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        string s;
        cin >> s;
        int N = s.size();
        int prev = 0;
        ll ans = 0;
        rep(i, N) {
            if (s[i] == '1') {
                ans++;
                string now;
                now += s[i];
                int inc = i + 1;
                int box = 1 + prev;
                while (inc < N) {
                    now += s[inc];
                    box++;
                    ll num = stoll(now, 0, 2);
                    if (num <= box) {
                        ans++;
                    } else {
                        break;
                    }
                    inc++;
                }
                prev = 0;
            } else {
                prev++;
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
