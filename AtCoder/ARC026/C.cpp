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

template<class T>
class SegmentTree {
    int n;
    vector<T> data;
    T def;
    function<T(T, T)> operation;
    function<T(T, T)> update;

    T _query(int a, int b, int k, int l, int r) {
        // 交差しない
        if (r <= a || b <= l) return def;
        // 区間 [a, b) に l, r が含まれる
        if (a <= l && r <= b) return data[k];
        // 左の子
        T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
        // 右の子
        T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(c1, c2);
    }

public:
    /**
     * @param _n size
     * @param _def initial value
     * @param _operation operation for query
     * @param _update operation for update
     */
    SegmentTree(size_t _n, T _def, function<T(T, T)> _operation, function<T(T, T)> _update)
            : def(_def), operation(move(_operation)), update(move(_update)) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }

    /**
     * iの値をxに更新
     * @param i index ( 0-indexed )
     * @param x  value
     */
    void change(int i, T x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    /**
     * [a, b)の区間でクエリを実行
     */
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }

    /**
     * 添字でアクセス
     * @param i index ( 0-indexed )
     */
    T operator[](int i) {
        return data[i + n - 1];
    }
};


/**
 * C - 蛍光灯
 * https://atcoder.jp/contests/arc026/tasks/arc026_3
 *
 * dp[i] = 西端から距離 i のところまでの全体を照らすのに必要な最小費用とする。
 * クエリを l が小さい順にソートしてからみていく。
 * 必ず r が次の蛍光灯の区間を含むので dp[r] のみを更新すればよい。
 * 更新は dp[l], ..., dp[r] の最小値 + c なので　RMQ (セグ木) で実現できる
 */
void Main() {
    int N, L;
    cin >> N >> L;
    vector<pair<int, pair<int, ll>>> items;
    SegmentTree<ll> segmentTree(L + 1, INF, [](ll a, ll b) { return min(a, b); }, [](ll a, ll b) { return min(a, b); });
    rep(i, N) {
        int l, r;
        ll c;
        cin >> l >> r >> c;
        items.push_back({l, {r, c}});
    }
    sort(items.begin(), items.end());

    vector<ll> dp(L + 1, INF);
    segmentTree.change(0, 0);
    rep(i, N) {
        int r = items[i].second.first;
        int l = items[i].first;
        ll c = items[i].second.second;
        ll x = segmentTree.query(l, r + 1);
        if (i == 0) x = 0;
        ll tmp = x + c;
        dp[r] = min(dp[r], tmp);
        segmentTree.change(r, tmp);
    }
    if (dp[L] < INF) {
        cout << dp[L] << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
