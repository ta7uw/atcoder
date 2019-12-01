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
 * D. Power Products
 * https://codeforces.com/contest/1247/problem/D
 *
 * 素因数分解して p ^ x の x について K で mod をとることで
 * 相手役が求まる。逆にこちらが提供できるものを求まる。
 * 同じ組を 1 度 だけ数えるように注意する。
 * また 1 は特別なので別で扱った方が楽。
 * オーバーフローを考慮すると直接値を保持するのではなく vector<P> を key とするような map で管理する
 */

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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    map<vector<P>, int> B;
    ll ans = 0;
    int cnt = 0;
    rep(i, N) {
        int a = A[i];

        auto p_map = prime_factorize(a);
        if (p_map.empty()) {
            ans += cnt;
            cnt++;
        } else {
            vector<P> b;
            vector<P> c;
            for (P x: p_map) {
                ll beki = K - (x.second % K);
                beki %= K;
                if (beki != 0) {
                    c.emplace_back(x.first, beki);
                    b.emplace_back(x.first, x.second % K);
                }
            }
            if (c.empty()) {
                ans += cnt;
                cnt++;
            } else {
                ans += B[c];
                B[b]++;
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
