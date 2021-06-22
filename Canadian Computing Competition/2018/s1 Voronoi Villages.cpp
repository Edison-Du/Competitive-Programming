#include <bits/stdc++.h>
using namespace std;

int n;
double ans;
vector<int> vil;
vector<double> dis;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        vil.push_back(v);
    }
    sort(vil.begin(), vil.end());
    for (int i = 1; i < n; i++) {
        dis.push_back((vil[i]+vil[i-1])/2.0);
    }
    ans = INT_MAX;
    for (int i = 1; i < n-1; i++) {
        ans = min(ans, dis[i]-dis[i-1]);
    }
    printf("%.1f", ans);
    return 0;       
}