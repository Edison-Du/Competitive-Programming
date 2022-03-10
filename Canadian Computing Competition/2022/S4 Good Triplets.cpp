#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = (int)1e6+5;

ll n, c, circle[MAXN];
ll getAllTriangles() {
    ll ret = 0;
    ll sum = circle[0];
    ll roll = circle[0] * circle[1];
    for (int i = 2; i < c; i++) {
        ret += circle[i] * roll;
        sum += circle[i-1];
        roll += circle[i] * sum;
    }
    return ret;
}
ll getBadTriangles() {
    ll ret = 0, rollingSum = 0, middle = 0;
    int sz = c/2 + 1;

    for (int i = 1; i < sz-1; i++) {
        middle += circle[i-1];
        rollingSum += circle[i] * middle;
    }
    
    // Sliding window size of the diameter to count bad triangles
    for (int i = sz-1; i < sz+c-1; i++) {
        ret += circle[i%c] * rollingSum;
        middle -= circle[(i-sz+1)%c];
        middle += circle[(i-1)%c];
        rollingSum -= circle[(i-sz+1)%c] * middle;
        rollingSum += circle[i%c] * middle;
    }
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        circle[a]++;
    }
    ll ans = getAllTriangles() - getBadTriangles();
    cout << ans << endl;
    return 0;
}