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

template<class T>
class SegmentTree {

public:
    /**
     * @param N size
     * @param e identity element
     * @param operation operation for query
     * @param updater operation for update
     */
    SegmentTree(size_t N, T e, function<T(T, T)> operation, function<T(T, T)> updater)
            : e(e), operation(std::move(operation)), updater(move(updater)) {
        n = 1;
        while (n < N) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, e);
    }

    /**
     * iの値をxに更新
     * @param i index ( 0-indexed )
     * @param x  value
     */
    void update(int i, T x) {
        i += n - 1;
        data[i] = updater(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    /**
     * [a, b)の区間でクエリを実行
     */
    T query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * 添字でアクセス
     * @param i index ( 0-indexed )
     */
    T operator[](int i) {
        return data[i + n - 1];
    }

private:
    int n;
    vector<T> data;
    T e;
    function<T(T, T)> operation;
    function<T(T, T)> updater;

    T query(int a, int b, int k, int l, int r) {
        // 交差しない
        if (r <= a || b <= l) return e;
        // 区間 [a, b) に l, r が含まれる
        if (a <= l && r <= b) return data[k];
        // 左の子
        T c1 = query(a, b, 2 * k + 1, l, (l + r) / 2);
        // 右の子
        T c2 = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(c1, c2);
    }
};

/**
 * F. Wi-Fi
 * https://codeforces.com/contest/1216/problem/F
 *
 * セグ木 + DP
 * コスト i + 1 でまかなえる領域をクエリとして保持する。
 * クエリを右端でソートして、dp[i] i までインターネットに接続するための最小コストとする。
 * dp[i] を求めるにはクエリ[l, r) に対して dp[l], ... dp[r-1] から最小値を求める必要がある。
 * 愚直に求めると間に合わないのでセグ木を使って高速化する。
 */
void Main() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector<ll>> query;
    rep(i, N) {
        if (S[i] == '0') {
            query.push_back(vector<ll>{i + 1, i, i + 1});
        } else {
            query.push_back(vector<ll>{min(N, i + K + 1), max(0LL, i - K), i + 1});
        }
    }
    sort(query.begin(), query.end());
    ll M = (ll) query.size();
    vector<ll> dp(N + 1, INF);
    SegmentTree<ll> segmentTree(N + 1, INF, [](ll a, ll b) { return min(a, b); }, [](ll a, ll b) { return min(a, b); });
    dp[0] = 0;
    segmentTree.update(0, 0);
    rep(i, M) {
        ll r = query[i][0];
        ll l = query[i][1];
        ll c = query[i][2];
        ll tmp = segmentTree.query(l, r) + c;
        dp[r] = min(dp[r], tmp);
        segmentTree.update(r, dp[r]);
    }
    cout << dp[N] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
