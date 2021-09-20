#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = (int)2e3+5;

struct window {
    ll x1, y1, x2, y2, t;
};

ll n, k, ans;
vector<window> windows;
ll psa[MAX][MAX];
vector<ll> xVal, yVal;
set<int> allX, allY;
map<int, int> idx, idy;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        ll x1, y1, x2, y2, t;
        cin >> x1 >> y1 >> x2 >> y2 >> t;
        allX.insert(x1);
        allX.insert(x2);
        allY.insert(y1);
        allY.insert(y2);
        windows.push_back({x1, y1, x2, y2, t});
    }
    int id = 0;
    for (int i : allX) {
        idx[i] = ++id;
        xVal.push_back(i);
    }
    id = 0;
    for (int i : allY) {
        idy[i] = ++id;
        yVal.push_back(i);
    }
    for (int i = 0; i < n; i++) {
        psa[idx[windows[i].x1]][idy[windows[i].y1]] += windows[i].t;
        psa[idx[windows[i].x1]][idy[windows[i].y2]] -= windows[i].t;
        psa[idx[windows[i].x2]][idy[windows[i].y1]] -= windows[i].t;
        psa[idx[windows[i].x2]][idy[windows[i].y2]] += windows[i].t;
    }
    for (int i = 1; i <= allX.size(); i++) {
        for (int j = 1; j <= allY.size(); j++) {
            psa[i][j] += psa[i][j-1] + psa[i-1][j] - psa[i-1][j-1];
            if (psa[i][j] >= k) {
                ans += (xVal[i]-xVal[i-1])*(yVal[j]-yVal[j-1]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}