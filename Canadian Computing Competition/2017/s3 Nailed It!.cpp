#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)2e3+5;

int n, frq[MAX], most, ans;
map<int,int> sum;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        frq[l]++;
    }
    for (int i = 1; i < MAX-1; i++) {
        for (int j = i; j < MAX; j++) {
            if (i == j) sum[i+j] += frq[i]/2;
            else sum[i+j] += min(frq[i],frq[j]);
        }
    }
    for (auto i : sum) {
        most = max(most, i.second);
    }
    for (auto i : sum) {
        if (i.second == most) ans++;
    }
    cout << most << " " << ans << endl;
    return 0;       
}