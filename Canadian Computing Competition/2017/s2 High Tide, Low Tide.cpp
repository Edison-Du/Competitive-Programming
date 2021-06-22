#include <bits/stdc++.h>
using namespace std;

int n, arr[105];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < (n+1)/2; i++) {
        cout << arr[(n+1)/2-i-1] << " ";
        if (arr[(n+1)/2+i] > 0) cout << arr[(n+1)/2+i] << " ";
    }
    return 0;       
}