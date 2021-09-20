#include <bits/stdc++.h>
using namespace std;

int g, p;
set<int> gates;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> g >> p;
    for (int i = 1; i <= g; i++) gates.insert(-i);
    while (p--) {
        int gi;
        cin >> gi;
        auto it = gates.lower_bound(-gi);
        if (it == gates.end()) break;
        else {
            gates.erase(it);
        }
    }
    cout << g-gates.size();
    return 0;       
}