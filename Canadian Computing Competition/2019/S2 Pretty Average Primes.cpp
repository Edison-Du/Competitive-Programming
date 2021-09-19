#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)2e6+5;

int t, n, seive[MAX];
set<int> primes;
void solve() {
    cin >> n;
    for (auto i = primes.begin(); (*i) <= n; i++) {
        int nxt = n+n-*i;
        if (nxt < MAX) {
            if (!seive[nxt]) {
                cout << *i << " " << nxt << endl;
                return;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 3; i < MAX; i += 2) {
        if (!seive[i]) {
            primes.insert(i);
            for (int j = i+i; j <= MAX; j += i) {
                seive[j] = 1;
            }
        }
    }
    cin >> t;
    while (t--) solve();
    return 0;       
}