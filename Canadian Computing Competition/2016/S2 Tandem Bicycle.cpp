#include <bits/stdc++.h>
using namespace std;

int t, n, a[105], b[105], ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a,a+n);
    sort(b,b+n);
    if (t == 1) {
        for (int i = 0; i < n; i++) ans += max(a[i],b[i]);
    }
    else {
        for (int i = 0; i < n; i++) ans += max(a[i], b[n-i-1]);
    }
    cout << ans << endl;
    return 0;       
}