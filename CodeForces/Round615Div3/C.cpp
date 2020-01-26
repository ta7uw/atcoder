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

map<ll, ll> prime_factorize(ll N) {
    map<ll, ll> res;
    for (ll i = 2; i * i <= N; ++i) {
        while (N % i == 0) {
            res[i]++;
            N /= i;
        }
    }
    if (N != 1) res[N] = 1;
    return res;
}

void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N;
        cin >> N;
        auto p = prime_factorize(N);
        if (p.size() == 1) {
            ll v = p.begin()->first;
            ll e = p.begin()->second;
            if (e >= 6) {
                cout << "YES" << '\n';
                cout << v << ' ' << v * v << ' ' << N / (v * v * v) << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else if (p.size() == 2) {
            ll cnt = 0;
            for (P a : p) {
                cnt += a.second;
            }
            if (cnt >= 4) {
                ll s = 1;
                cout << "YES" << '\n';
                for (P a : p) {
                    cout << a.first << ' ';
                    s *= a.first;
                }
                cout << N / s << '\n';
            } else {
                cout << "NO" << '\n';
            }
        } else {
            cout << "YES" << '\n';
            int i = 0;
            ll s = 1;
            for (P a : p) {
                cout << a.first << ' ';
                i++;
                s *= a.first;
                if (i == 2) break;
            }
            cout << N / s << '\n';
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
