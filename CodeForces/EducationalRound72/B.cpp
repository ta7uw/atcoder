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
        int n, x;
        cin >> n >> x;
        vector<P> info(n);
        ll max_b = 0;
        ll con = 0;
        rep(i, n) {
            cin >> info[i].first >> info[i].second;
            max_b = max(max_b, info[i].first);
            con = max(con, info[i].first - info[i].second);
        }
        //sort(info.begin(), info.end(), greater<>());
        if (max_b >= x) {
            cout << 1 << endl;
        } else {
            if (con == 0) {
                cout << -1 << endl;
            } else {
                cout << (x - max_b + con - 1) / con + 1 << endl;
            }
        }
    }

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
