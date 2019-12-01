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
 * D. Yet Another Monster Killing Problem
 * https://codeforces.com/contest/1257/problem/D
 *
 * セグ木で s が [x, N+1) の最大 p をとれるようにして A をqueue に詰めて先頭からシミュレーションすれば解ける。
 * これまで連続して倒したモンスターを保持してそれをしたまわらないようにする
 */
void Main() {
    int T;
    cin >> T;
    rep(t, T) {
        int N;
        cin >> N;
        deque<int> A;
        rep(i, N) {
            int a;
            cin >> a;
            A.push_back(a);
        }
        int M;
        cin >> M;
        SegmentTree<int> segmentTree(N + 1, 0, [](int a, int b) { return max(a, b); }, [](int a, int b) { return max(a, b); });
        rep(i, M) {
            int p, s;
            cin >> p >> s;
            segmentTree.update(s, p);
        }

        int ans = 0;
        int length = 0;
        int max_monster = 0;
        bool fail = false;
        while (!A.empty()) {
            int a = A.front();
            A.pop_front();
            max_monster = max(a, max_monster);
            length++;
            int max_hero = segmentTree.query(length, N + 1);
            if (max_hero >= a && max_hero >= max_monster) {
                continue;
            } else if (length == 1) {
                fail = true;
                break;
            } else {
                ans++;
                A.push_front(a);
                length = 0;
                max_monster = 0;
            }
        }
        if (fail) {
            cout << -1 << '\n';
        } else {
            ans++;
            cout << ans << '\n';
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
