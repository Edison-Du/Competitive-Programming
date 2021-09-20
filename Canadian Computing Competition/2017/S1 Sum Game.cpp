#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5+5;

int n, a[MAX], b[MAX];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i-1];
    }
    for (int i = n; i >= 0; i--) {
        if (a[i] == b[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;       
}