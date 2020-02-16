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

bool compare(pair<ll, P> a, pair<ll, P> b) {
    if(a.first != b.first){
        return a.first < b.first;
    }else{
        return abs(a.second.first - a.second.second) >  abs(b.second.first - b.second.second);
    }
}


void Main() {
    int Q;
    cin >> Q;
    rep(q, Q) {
        ll N, M;
        cin >> N >> M;
        vector<pair<ll, P>> cus(N);
        rep(i, N) cin >> cus[i].first >> cus[i].second.first >> cus[i].second.second;
        sort(cus.begin(), cus.end(), compare);
        ll L = M;
        ll R = M;
        bool ok = true;
        ll last = 0;
        rep(i, N) {
            ll t = cus[i].first;
            ll l = cus[i].second.first;
            ll r = cus[i].second.second;
            //print(l, r);
            L = L - (t - last);
            R = R + (t - last);
            if (!((R < l) || (r < L))){
                L = max(L, l);
                R = min(R, r);
            } else {
                ok = false;
            }
            last = t;
        }
        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
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
