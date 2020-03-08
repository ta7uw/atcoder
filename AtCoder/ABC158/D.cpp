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
    string S;
    cin >> S;
    ll Q;
    cin >> Q;

    deque<char> ans;
    ll N = S.size();
    rep(i, N) {
        ans.push_back(S[i]);
    }
    bool front = true;
    rep(q, Q) {
        ll n;
        cin >> n;
        if (n == 1) {
            front ^= true;
        } else {
            ll f;
            cin >> f;
            char c;
            cin >> c;
            if (f == 1) {
                if (front) {
                    ans.push_front(c);
                } else {
                    ans.push_back(c);
                }
            } else {
                if (front) {
                    ans.push_back(c);
                } else {
                    ans.push_front(c);
                }
            }
        }
    }
    if (front) {
        rep(i, ans.size()) {
            cout << ans[i];
        }
    } else {
        rrep(i, ans.size() - 1, 0) {
            cout << ans[i];
        }
    }
    cout << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
