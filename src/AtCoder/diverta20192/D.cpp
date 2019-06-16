#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
#define rep(i, m, n) for(int i=m;i<n;i++)
#define rrep(i, n, m) for(int i=n;i>=m;i--)

ll dp[25000010] = {};
ll dp2[25000010] = {};

int main() {
    int n;
    cin >> n;
    int a[3];
    int b[3];
    for (int & i : a) {
        cin >> i;
    }
    for (int & i : b) {
        cin >> i;
    }

    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 1;
        for (int j = 0; j < 3; ++j) {
            int ga = a[j];
            int gb = b[j];
            if (i - ga >= 0) {
                dp[i] = max(dp[i], dp[i - ga] + gb);
            }
        }
    }
    ll res = dp[n];

    for (int i = 1; i <= res; ++i) {
        dp2[i] = dp2[i - 1] + 1;
        for (int j = 0; j < 3; ++j) {
            int ga = a[j];
            int gb = b[j];
            if (i - gb >= 0) {
                dp2[i] = max(dp2[i], dp2[i - gb] + ga);
            }
        }
    }
    cout << dp2[res] << endl;
}
