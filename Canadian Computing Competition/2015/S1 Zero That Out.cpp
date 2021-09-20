#include <bits/stdc++.h>
using namespace std;

int k, ans;
vector<int> vi;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    while (k--) {
        int x;
        cin >> x;
        if (x) vi.push_back(x);
        else vi.pop_back();
    }
    for (int i : vi) ans += i;
    cout << ans << endl;
    return 0;       
}