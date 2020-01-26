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

template<class Monoid, class Lazy>
class LazySegmentTree {

public:

    /**
     * @param N size
     * @param initial_val initial value in `data`
     * @param def identity element
     * @param def_lazy identity element for `lazy`
     * @param operation operation to merge `data`
     * @param lazy_operation operation to update `data` using `lazy`
     * @param lazy_updater operation to update `lazy`
     * @param lazy_calc operation to calculate `lazy` value from length
     */
    LazySegmentTree(int N, Monoid initial_val, Monoid def, Lazy def_lazy,
                    function<Monoid(Monoid, Monoid)> operation,
                    function<Monoid(Monoid, Lazy)> lazy_operation,
                    function<Lazy(Lazy, Lazy)> lazy_updater,
                    function<Lazy(Lazy, ll)> lazy_calc)
            : initial_val(initial_val), def(def), def_lazy(def_lazy), operation(operation),
              lazy_operation(std::move(lazy_operation)), lazy_updater(std::move(lazy_updater)),
              lazy_calc(std::move(lazy_calc)) {
        n = 1;
        while (n < N) {
            n *= 2;
        }
        data = vector<Monoid>(2 * n - 1, initial_val);
        lazy = vector<Monoid>(2 * n - 1, def_lazy);

        for (int i = n - 2; i >= 0; i--) {
            data[i] = operation(data[2 * i + 1], data[2 * i + 2]);
        }
    }

    /**
     * 区間更新 [a, b)
     * O(logN)
     */
    void update(int a, int b, Lazy x) {
        update(a, b, x, 0, 0, n);
    }

    /**
     * 区間取得 [a, b)
     * O(logN)
     */
    Monoid query(int a, int b) {
        return query(a, b, 0, 0, n);
    }

    /**
     * 添字でアクセス( 0-indexed )
     */
    Monoid operator[](int i) {
        return data[i + n - 1];
    }

private:
    int n;
    vector<Monoid> data;
    vector<Lazy> lazy;
    Monoid initial_val;
    Monoid def;
    Lazy def_lazy;

    // To merge data
    function<Monoid(Monoid, Monoid)> operation;

    // To update data using lazy
    function<Monoid(Monoid, Lazy)> lazy_operation;

    // To update lazy
    function<Lazy(Lazy, Lazy)> lazy_updater;

    // To calculate lazy value using length
    function<Lazy(Lazy, ll)> lazy_calc;

    void eval(int l, int r, int k) {

        // 遅延伝播用の配列の値が初期値と同じかどうかを比較
        if (lazy[k] == def_lazy) return;

        if (r - l > 1) {
            lazy[2 * k + 1] = lazy_updater(lazy[2 * k + 1], lazy[k]);
            lazy[2 * k + 2] = lazy_updater(lazy[2 * k + 2], lazy[k]);
        }

        // k 番目ノードの値に対して遅延評価を行う
        data[k] = lazy_operation(data[k], lazy_calc(lazy[k], r - l));

        // 遅延伝播用の配列の値を初期値に戻す
        lazy[k] = def_lazy;
    }

    Monoid update(int a, int b, Monoid x, int k, int l, int r) {
        eval(l, r, k);
        if (r <= a || b <= l) return data[k];
        if (a <= l && r <= b) {
            lazy[k] = lazy_updater(lazy[k], x);
            return lazy_operation(data[k], lazy_calc(lazy[k], r - l));
        }

        return data[k] = operation(update(a, b, x, 2 * k + 1, l, (l + r) / 2),
                                   update(a, b, x, 2 * k + 2, (l + r) / 2, r));
    }

    Monoid query(int a, int b, int k, int l, int r) {

        // 交差しない
        if (b <= l || r <= a) {
            return def;
        }

        // 取得時に評価
        eval(l, r, k);

        // 区間 [a, b) に l, r が含まれる
        if (a <= l && r <= b) {
            return data[k];
        }
        // 左の子
        Monoid vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
        // 右の子
        Monoid vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
        return operation(vl, vr);
    }
};

void Main() {
    ll N, D, A;
    cin >> N >> D >> A;
    vector<P> items(N);
    rep(i, N) cin >> items[i].first >> items[i].second;
    LazySegmentTree<ll, ll> lazySegmentTree(N, 0, INF, 0, [](ll a, ll b) { return min(a, b); },
                                            [](ll a, ll b) { return a + b; },
                                            [](ll a, ll b) { return a + b; },
                                            [](ll a, ll b) { return a; });
    sort(items.begin(), items.end());
    vector<ll> grid;
    rep(i, N) {
        P p = items[i];
        grid.push_back(p.first);
        lazySegmentTree.update(i, i + 1, p.second);
    }
    ll ans = 0;
    rep(i, N) {
        ll tmp = lazySegmentTree.query(i, i + 1);
        if (tmp <= 0) continue;
        ll c = (tmp + A - 1) / A;
        ll x = grid[i];
        ans += c;
        ll idx = lower_bound(grid.begin(), grid.end(), x + 2 * D + 1) - grid.begin();
        lazySegmentTree.update(i, idx, - c * A);
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
