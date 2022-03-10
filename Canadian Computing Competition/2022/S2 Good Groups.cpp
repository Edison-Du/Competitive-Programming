#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5+5;

int x, y, g, ans;
string same[2][MAXN], diff[2][MAXN];
map<string, int> mp;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> x;
    for (int i = 0; i < x; i++) {
        cin >> same[0][i] >> same[1][i];
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        cin >> diff[0][i] >> diff[1][i];
    }
    cin >> g;
    for (int i = 0; i < g; i++) {
        string a, b, c;
        cin >> a >> b >> c;
        mp[a] = mp[b] = mp[c] = i;
    }
    for (int i = 0; i < x; i++) {
        if (mp[same[0][i]] != mp[same[1][i]]) ans++;
    }
    for (int i = 0; i < y; i++) {
        if (mp[diff[0][i]] == mp[diff[1][i]]) ans++;
    }
    cout << ans << endl;
    return 0;
}