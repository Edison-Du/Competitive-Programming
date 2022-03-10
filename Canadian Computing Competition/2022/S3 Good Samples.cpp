#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = (int)1e6+5;

ll n, m, k, ans[MAXN];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> k;
    ll cur = 0;
    int lastIndex = n + 1, lastDuplicate = 0;
    for (int i = 1; i <= n; i++) {
        if (cur + n <= k && i <= m) {
            cur += (ans[i] += i);
        } else {
            lastIndex = i;
            break;
        }
    }
    for (int i = lastIndex; i <= n; i++) {
        ll most = min(k - cur - (n - i), (ll)i - lastDuplicate - 1);
        if (i - most > 0) {
            lastDuplicate = i-most;
            ans[i] = ans[i-most];
        }
        cur += most;
    }
    if (cur == k) {
        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    } else {
        cout << -1 << endl; 
        return 0;
    }
    return 0;
}