#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e4+5;

int n, h[MAX], w[MAX];
double ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i <= n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) {
        ans += w[i] * (h[i]+h[i+1]);
    }
    cout << fixed << ans/2 << endl;
    return 0;       
}