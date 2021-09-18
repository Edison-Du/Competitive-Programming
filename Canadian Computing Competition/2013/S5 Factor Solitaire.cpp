#include <bits/stdc++.h>
using namespace std;

int n, cost; 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    while (n != 1) {
        int best = n;
        for (int i = n-1; i >= (n+1)/2; i--) {
            if (i%(n-i) == 0) best = i;
        }
        cost += best/(n-best);
        n -= n-best;
    }
    cout << cost << endl;
    return 0;       
}