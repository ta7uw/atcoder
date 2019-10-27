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
 * A. Forgetting Things
 * https://codeforces.com/contest/1247/problem/A
 * 注意力
 * a = b, a + 1 = b, a = 9, b = 1, のケースで達成できる
 */
void Main() {
    int a, b;
    cin >> a >> b;
    if (abs(b - a) > 1 || a > b) {
        if(a == 9 && b == 1) {
            cout << a * 10 + 9 << " " << b * 100 << '\n';
        }else{
            cout << -1 << '\n';
        }
    } else if (a == b) {
        cout << a * 10 + 8 << " " << b * 10 + 9 << '\n';
    } else{
        cout << a * 10 + 9 << " " << b * 10<< '\n';
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}
