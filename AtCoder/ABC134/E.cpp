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
    vector<int> A(N);
    for (auto& a : A ) {
        cin >> a;
    }

    vector<int> que;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int a = A[i];
        if (i == 0) {
            que.push_back(a);
            ans ++;
        }else{
            int idx = upper_bound(que.begin(), que.end(), a-1) - que.begin();
            if (idx == 0) {
                que.insert(que.begin(), a);
                ans ++;
            }else{
                que[idx-1] = a;
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
