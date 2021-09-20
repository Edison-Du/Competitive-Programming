#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = (int)1e5+5;

ll n, w, c, ans, arr[MAX];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> w >> n;
    for (ans = 0; ans < n; ans++) {
        cin >> arr[ans];
        c += arr[ans];
        if (ans > 3) c -= arr[ans-4];
        if (c > w) break;
    }
    cout << ans << endl;
    return 0;       
}