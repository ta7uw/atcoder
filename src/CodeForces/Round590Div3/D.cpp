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
 * D. Distinct Characters Queries
 * https://codeforces.com/contest/1234/problem/D
 * BITでアルファベットのvectorを管理させる。
 * 2次元BITの亜種。eraseメソッドを生やした。
 */
class BinaryIndexedTree {
    int N;
    vector<vector<int>> data;
public:
    BinaryIndexedTree(int N) : N(N) {
        data.resize(N + 1, vector<int>(26, 0));
    }

    unordered_map<int, int> sum(int k) {
        unordered_map<int, int> alpha;
        for (; k > 0; k -= k & -k) {
            for (int i = 0; i < 26; ++i) {
                if (data[k][i] >= 1) {
                    alpha[i] += data[k][i];
                }
            }
        }
        return alpha;
    }

    void add(int k, int x) {
        for (; k <= N; k += k & -k) {
            data[k][x]++;
        }
    }

    void erase(int k, int x) {
        for (; k <= N; k += k & -k) {
            data[k][x]--;
        }
    }
};


void Main() {
    string S;
    cin >> S;
    int Q;
    cin >> Q;
    int N = S.size();
    BinaryIndexedTree bit(N);
    vector<int> T(N, -1);
    rep(i, N) {
        char s = S[i];
        T[i] = s - 'a';
        bit.add(i + 1, s - 'a');
    }
    rep(q, Q) {
        int c;
        cin >> c;
        if (c == 1) {
            int x;
            char s;
            cin >> x >> s;
            bit.erase(x, T[x - 1]);
            T[x - 1] = s - 'a';
            bit.add(x, s - 'a');
        } else {
            int l, r;
            cin >> l >> r;
            unordered_map<int, int> L = bit.sum(l - 1);
            unordered_map<int, int> R = bit.sum(r);
            unordered_map<int, int> ans;
            for (auto p: L) {
                R[p.first] -= p.second;
            }
            int res = 0;
            for (auto p: R) {
                if (p.second >= 1) {
                    res++;
                }
            }
            cout << res << '\n';
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
