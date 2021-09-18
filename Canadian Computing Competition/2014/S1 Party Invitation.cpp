#include <bits/stdc++.h>
using namespace std;

int k, m, r, arr[105];
vector<int> vi;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k >> m;
    for (int i = 1; i <= k; i++) vi.push_back(i);
    while (m--) {
        cin >> r;
        for (int i = 0; i < vi.size(); i++) {
            if ((i+1) % r == 0) arr[i] = 1;
            else arr[i] = 0;
        }
        for (int i = vi.size()-1; i >= 0; i--) {
            if (arr[i]) vi.erase(vi.begin()+i);
        }
    }
    for (int i : vi) cout << i << endl;
    return 0;       
}