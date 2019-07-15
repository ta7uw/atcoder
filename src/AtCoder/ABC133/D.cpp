#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;
#ifdef __DEBUG
#include "cpp-pyprint/pyprint.h"
#endif

void Main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    for (auto &v : a) {
        cin >> v;
    }

    vector<ll> ans(N, 0);
    ll tmp = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0){
            tmp += a[i];
        }else{
            tmp -= a[i];
        }
    }
    ans[0] = tmp;
    for (int j = 1; j < N; ++j) {
        ans[j] = 2 * (a[j-1] - ans[j - 1] / 2 );
    }
    for (auto v : ans ) {
        cout << v << " ";
    }
    cout << endl;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
