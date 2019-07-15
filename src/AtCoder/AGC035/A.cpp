#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>

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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (auto &a: A) {
        cin >> a;
    }
    map<int, int> dict;
    for (auto a : A) {
        dict[a] += 1;
    }

    if (dict.count(0) && dict[0] == N) {
        cout << "Yes" << endl;
    } else if (dict.count(0) && dict.size() == 2 && dict[0] == N / 3) {
        cout << "Yes" << endl;
    } else if (dict.size() == 3) {
        bool flag = true;
        int x = 1;
        for (auto &p : dict) {
            x ^= p.first;
            if (p.second == N / 3) {
                continue;
            } else {
                flag = false;
            }
        }
        if (x == 1 && flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }
}
