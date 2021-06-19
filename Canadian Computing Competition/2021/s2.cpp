#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = (int)5e6+5;

ll n, m, k, row[MAX], col[MAX], tot, ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        char c; int j;
        cin >> c >> j;
        if (c == 'R') row[j] = (row[j]+1) % 2;
        else col[j] = (col[j]+1) % 2;
    }
    for (int i = 1; i <= n; i++) tot += row[i];
    for (int i = 1; i <= m; i++) {
        if (col[i]) ans += n-tot;
        else ans += tot;
    }
    cout << ans << endl;
    return 0;       
}