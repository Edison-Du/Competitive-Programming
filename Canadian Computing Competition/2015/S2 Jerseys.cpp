#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e6+5;

int j, a, ans, sold[MAX];
char jerseys[MAX];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> j >> a;
    for (int i = 1; i <= j; i++) cin >> jerseys[i];
    while (a--) {
        char sz;
        int num;
        cin >> sz >> num;
        if (!sold[num] && jerseys[num] <= sz) {
            sold[num]=1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}