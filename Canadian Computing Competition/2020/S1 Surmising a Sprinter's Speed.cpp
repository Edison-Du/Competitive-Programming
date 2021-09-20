#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int n;
double ans;
vector<pll> pos;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll t, x;
        cin >> t >> x;
        pos.push_back({t, x});
    }
    sort(pos.begin(), pos.end());
    for (int i = 1; i < n; i++) {
        double dx = abs(pos[i].second-pos[i-1].second);
        double dt = pos[i].first-pos[i-1].first;
        ans = max(ans, dx/dt);
    }
    cout << fixed << ans << endl;
    return 0;       
}