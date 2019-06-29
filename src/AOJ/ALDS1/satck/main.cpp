#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<stack>
#include<utility>
#include<cassert>
#include <stdlib.h>

using namespace std;

const int MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
    string s;
    stack<int> st;
    while (cin >> s) {
        if (s[0] == '+') {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b + a);
        } else if (s[0] == '-') {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b - a);
        } else if (s[0] == '*') {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            st.push(b * a);
        } else {
            st.push(atoi(s.c_str()));
        }
        if(getchar()=='\n'){
            break;
        }
    }
    cout << st.top() << endl;
}

