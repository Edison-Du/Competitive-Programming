#include <bits/stdc++.h>
using namespace std;

int n, arr[405], dp[405][405], ans;
int sum(int l, int r) {
    return arr[r] - arr[l-1];
}
bool combineTwo(int l, int r) {
    for (int i = l; i < r; i++) {
        if (dp[l][i] && dp[i+1][r]) {
            if (sum(l,i)==sum(i+1,r)) {
                return 1;
            }
        }
    }
    return 0;
}
bool combineThree(int l, int r) {
    int ri = r;
    for (int li = l; li < ri-1; li++) {
        while(sum(l,li)>sum(ri,r) && (li+1 < ri-1)) ri--;
        if (dp[l][li] && dp[ri][r] && dp[li+1][ri-1]) {
            if (sum(l,li)==sum(ri,r)) return 1;
        }
        
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] += arr[i-1];
    }
    for (int i = 1; i <= n; i++) dp[i][i] = 1;
    for (int w = 2; w <= n; w++) {
        for (int l = 1; l <= n-w+1; l++) {
            if (combineTwo(l,l+w-1)) {
                dp[l][l+w-1] = 1;
            } else if (combineThree(l,l+w-1)) {
                dp[l][l+w-1] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (dp[i][j]) {
                ans = max(ans, sum(i,j));
            }
        }
    }
    cout << ans << endl;
    return 0;       
}