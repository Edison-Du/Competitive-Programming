#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5+5;

int t, n, arr[MAX], cur;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        cur = 1;
        stack<int> st;
        for (int i = n; i > 0; i--) {
            if (arr[i] == cur) {
                cur++;
                while (st.size() && st.top() == cur) {
                    st.pop();
                    cur++;
                }
            } else {
                st.push(arr[i]);
            }
        }
        st.empty() ? cout << "Y\n" : cout << "N\n";
    }
    return 0;       
}