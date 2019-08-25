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

ll dp[100005][13];

void Main() {
    int n;
    cin >> n;
    priority_queue<double, vector<double>, greater<>> V;
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        V.push(v);
    }

    while (V.size() != 1) {
        double a = V.top();
        V.pop();
        double b = V.top();
        V.pop();
        V.push((a + b) / 2);
    }
    cout << abs(V.top()) << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
