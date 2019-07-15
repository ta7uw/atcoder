#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;i++)
#define rep2(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)
using Graph = vector<vector<int>>;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#ifdef __DEBUG

#include "cpp-pyprint/pyprint.h"

#endif

void Main() {
    int N, D;
    cin >> N >> D;
    vector<vector<int>> a(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < D; ++j) {
            int s;
            cin >> s;
            a[i].push_back(s);
        }
    }
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            if (i == j) {
                continue;
            }else{
                ll tmp = 0;
                for (int d = 0; d < D; ++d) {
                    int y = a[i][d];
                    int z = a[j][d];
                    tmp += pow(abs(z-y) , 2);
                }
                for (int x = 1; x <= tmp; ++x) {
                    if (pow(x, 2) == tmp) {
                        ans ++;
                        break;
                    }
                }
            }
        }
    }
    cout << ans << endl;

}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
