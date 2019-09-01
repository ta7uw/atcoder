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
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X);
    vector<ll> B(Y);
    vector<ll> C(Z);
    rep(i, X) cin >> A[i];
    rep(i, Y) cin >> B[i];
    rep(i, Z) cin >> C[i];
    priority_queue<ll> queue;
    rep(x, X) {
        rep(y, Y) {
            queue.push(A[x] + B[y]);
        }
    }
    vector<ll> target;
    ll tmp = min(K, X*Y);
    while (target.size() != tmp) {
        ll q = queue.top();
        queue.pop();
        target.push_back(q);
    }
    priority_queue<ll> ans;
    rep(i, tmp) {
        ll t = target[i];
        rep(z, Z) {
            ans.push(C[z] + t);
        }
    }

    int cnt = 0;
    while (cnt != K) {k
        cout << ans.top() << endl;
        ans.pop();
        cnt++;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}

