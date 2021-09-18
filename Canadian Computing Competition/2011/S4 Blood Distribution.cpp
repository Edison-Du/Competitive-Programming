#include <bits/stdc++.h>
using namespace std;

int ans, ans1, ans2;
vector<int> blood(8), patients(8);
vector<int> tempB(8), tempP(8);

int give (int b, int p, vector<int> &blood, vector<int> &patients) {
    int use = min(blood[b], patients[p]);
    blood[b] -= use;
    patients[p] -= use;
    return use;
}
void copy() {
    for (int i = 0; i < 8; i++) {
        tempB[i] = blood[i];
        tempP[i] = patients[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    for (int i = 0; i < 8; i++) cin >> blood[i];
    for (int i = 0; i < 8; i++) cin >> patients[i];

    for (int i = 0; i < 8; i++) {
        ans += give(i, i, blood, patients);
    }
    ans += give(0, 1, blood, patients);
    ans += give(0, 2, blood, patients);
    ans += give(0, 4, blood, patients);
    ans += give(3, 7, blood, patients);
    ans += give(5, 7, blood, patients);
    ans += give(6, 7, blood, patients);
    
    ans1 = ans2 = ans;

    copy();
    ans1 += give(2, 6, tempB, tempP);
    ans1 += give(2, 3, tempB, tempP);
    ans1 += give(2, 7, tempB, tempP);
    ans1 += give(4, 6, tempB, tempP);
    ans1 += give(4, 5, tempB, tempP);
    ans1 += give(4, 7, tempB, tempP);
    ans1 += give(0, 6, tempB, tempP);
    ans1 += give(0, 3, tempB, tempP);
    ans1 += give(0, 5, tempB, tempP);
    ans1 += give(0, 7, tempB, tempP);
    ans1 += give(1, 3, tempB, tempP);
    ans1 += give(1, 5, tempB, tempP);
    ans1 += give(1, 7, tempB, tempP);

    copy();
    ans2 += give(4, 6, tempB, tempP);
    ans2 += give(4, 5, tempB, tempP);
    ans2 += give(4, 7, tempB, tempP);
    ans2 += give(2, 6, tempB, tempP);
    ans2 += give(2, 3, tempB, tempP);
    ans2 += give(2, 7, tempB, tempP);
    ans2 += give(0, 6, tempB, tempP);
    ans2 += give(0, 3, tempB, tempP);
    ans2 += give(0, 5, tempB, tempP);
    ans2 += give(0, 7, tempB, tempP);
    ans2 += give(1, 3, tempB, tempP);
    ans2 += give(1, 5, tempB, tempP);
    ans2 += give(1, 7, tempB, tempP);
    
    cout << max(ans1, ans2) << endl;
    return 0;       
}