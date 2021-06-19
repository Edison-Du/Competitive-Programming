#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MAX = (int)6e5+5;

ll n, p[MAX], w[MAX], d[MAX], ans;
ll val, rtCost[MAX], ltCost[MAX];
vector<ll> pos;
vector<pll> rtDist, ltDist;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> w[i] >> d[i];
        pos.push_back(p[i]);
        pos.push_back(p[i]+d[i]);
        pos.push_back(p[i]-d[i]);
        rtDist.push_back({p[i]+d[i],i});
        ltDist.push_back({p[i]-d[i],i});
    }
    sort(pos.begin(),pos.end());
    sort(rtDist.rbegin(), rtDist.rend());
    sort(ltDist.begin(), ltDist.end());
    for (int i = 0; i < pos.size(); i++) {
        if (i > 0) {
            rtCost[i] += rtCost[i-1];
            rtCost[i] += val * (pos[i] - pos[i-1]);
        }
        for (int j = rtDist.size()-1; j >= 0; j--) {
            ll id = rtDist[j].second;
            if (rtDist[j].first > pos[i]) break;
            val += w[id];
            rtCost[i] += (pos[i]-rtDist[j].first)*w[id];
            rtDist.pop_back();
        }
    }
    val = 0;
    for (int i = pos.size()-1; i >= 0; i--) {
        if (i < pos.size()-1) {
            ltCost[i] += ltCost[i+1];
            ltCost[i] += val * (pos[i+1] - pos[i]);
        }
        for (int j = ltDist.size()-1; j >= 0; j--) {
            ll id = ltDist[j].second;
            if (ltDist[j].first < pos[i]) break;
            val += w[id];
            ltCost[i] += (ltDist[j].first-pos[i])*w[id];
            ltDist.pop_back();
        }
    }
    ans = LLONG_MAX;
    for (int i = 0; i < pos.size(); i++) {
        ans = min(ans, rtCost[i]+ltCost[i]);
    }
    cout << ans << endl;
    return 0;
}