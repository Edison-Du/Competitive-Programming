#include <bits/stdc++.h>
using namespace std;

int n, arr[105][105], tmp[105][105];
void rotate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[n-j-1][i] = arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = tmp[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    while (arr[0][0] > arr[0][1] || arr[0][0] > arr[1][0]) {
        rotate();
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;       
}