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

class BinaryIndexedTree {
    int N;
    vector<ll> data;
public:
    BinaryIndexedTree(int N) : N(N) {
        data.resize(N + 1, 0);
    }

    ll sum(int k) {
        ll res = 0;
        for (; k > 0; k -= k & -k) {
            res += data[k];
        }
        return res;
    }

    void add(int k, ll x) {
        for (; k <= N; k += k & -k) {
            data[k] += x;
        }
    }
};
/**
 * ARC031 C - 積み木
 * https://atcoder.jp/contests/arc031/submissions/7733224
 * 値の小さいものから見ていき、左右にどれだけ自身より大きい数があるのか数えて小さい方に移動する。
 * BITを用いて最初は全て1で初期化して見ていった数のインデックに-1を加算していく、
 * BITで管理しているものは必ず今見ている数より大きくなっているので単純に左右の和を求めればいい。
 */
void Main() {
    int N;
    cin >> N;
    vector<int> B(N);
    rep(i, N) {
        cin >> B[i];
    }
    BinaryIndexedTree bit(N);
    rep(i, N) {
        bit.add(i + 1, 1);
    }

    vector<int> C(N, 0);
    rep(i, N) {
        C[B[i]-1] = i + 1;
    }
    ll ans = 0;
    rep(i, N) {
        int c = C[i];
        ll right = bit.sum(N) - bit.sum(c);
        ll left = bit.sum(c-1);
        ans += min(left, right);
        bit.add(c, -1);
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
