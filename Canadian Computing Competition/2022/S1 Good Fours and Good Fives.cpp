#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, ans = 0; 
    cin >> n;
    while (n >= 0) {
        if (n % 5 == 0) ans++;
        n -= 4;
    }
    cout << ans << endl;
    return 0;
}