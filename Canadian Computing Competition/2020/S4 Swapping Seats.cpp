#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e6+5;

string s;
int ans, numA, numB, numC;
int psaA[MAXN], psaB[MAXN], psaC[MAXN];

int sum(int i, int l, int psa[]) {
    int tot = 0;
    i %= s.size();
    if (!l) return 0;
    else l--;
    if (i+l < s.size()) {
        tot = psa[i+l];
    } else {
        tot = psa[s.size()-1];
        tot += psa[i+l-s.size()];
    }
    if (i) tot -= psa[i-1];
    return tot;
}
int solve(int i) {
    int BinA, CinA, AinB, CinB, ret;

    // A - B - C
    BinA = sum(i, numA, psaB);
    CinA = sum(i, numA, psaC);
    AinB = sum(i + numA, numB, psaA);
    CinB = sum(i + numA, numB, psaC);
    ret = CinA + CinB + max(BinA, AinB);

    // A - C - B
    AinB = sum(i + numA + numC, numB, psaA);
    CinB = sum(i + numA + numC, numB, psaC);
    ret = min(ret, CinA + CinB + max(BinA, AinB));
    return ret;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    
    // Prefix sums for each letter
    for (int i = 0; i < s.size(); i++) {
        if (i) {
            psaA[i] = psaA[i-1];
            psaB[i] = psaB[i-1];
            psaC[i] = psaC[i-1];
        }
        if (s[i] == 'A') {psaA[i]++; numA++;}
        if (s[i] == 'B') {psaB[i]++; numB++;}
        if (s[i] == 'C') {psaC[i]++; numC++;}
    }

    ans = INT_MAX;
    for (int i = 0; i < s.size(); i++) {
        ans = min(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}