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
 * C. Stack of Presents
 * https://codeforces.com/contest/1279/problem/C
 *
 * B を貪欲の探索していく。
 * 一度取り出しことがあるものは一番上において + 1 でとれるものと考えて良い
 * 一度取り出したものは set で管理する。
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        ll N, M;
        cin >> N >> M;
        queue<ll> A;
        vector<ll> B(M);
        rep(i, N) {
            ll a;
            cin >> a;
            A.push(a);
        };
        rep(i, M) cin >> B[i];

        ll ans = 0;
        set<ll> used;
        ll fin = 0;
        while (fin < M) {
            ll target = B[fin];
            if (used.find(target) != used.end()) {
                ans++;
                fin++;
                used.erase(target);
                continue;
            }
            while (!A.empty()) {
                ll a = A.front();
                A.pop();
                if (a == target) {
                    fin++;
                    ans += 2 * used.size() + 1;
                    break;
                } else {
                    used.insert(a);
                }
            }
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
