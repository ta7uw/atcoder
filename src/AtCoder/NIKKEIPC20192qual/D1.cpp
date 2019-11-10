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

/***
 * D - Shortest Path on a Line
 * https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
 *
 * dp[i] = (頂点iまでの最短経路)とすると、
 * 辺を追加する操作は「各dp[L],…,dp[R]に対して、min(dp[L],…,dp[R])+Cとのminを取る」といえる。
 * あとは辺の追加をRの降順でやれば、min(dp[L],…,dp[R])を求める部分でセグ木を使って解ける。
 */
void Main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, pair<int, ll>>> items;
    SegmentTree<ll> segmentTree(N, INF, [](ll a, ll b) { return min(a, b); }, [](ll a, ll b){ return min(a, b); });
    rep(i, M) {
        int l, r;
        ll c;
        cin >> l >> r >> c;
        items.push_back({r, {l, c}});
    }
    sort(items.begin(), items.end());

    vector<ll> dp(N, INF);
    dp[0] = 0;
    segmentTree.change(0, 0);
    rep(i, M) {
        int r = items[i].first;
        int l = items[i].second.first;
        ll c = items[i].second.second;
        l--;
        r--;
        ll x = segmentTree.query(l, r + 1);
        ll tmp = x + c;
        dp[r] = min(dp[r], tmp);
        segmentTree.change(r, tmp);
    }
    if (dp[N - 1] != INF) {
        cout << dp[N - 1] << '\n';
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
