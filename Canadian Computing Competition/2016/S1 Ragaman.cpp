#include <bits/stdc++.h>
using namespace std;

int frq1[26], frq2[26], wild;
string a, b;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> a >> b;
    for (char i : a) {
        frq1[(int)i-'a']++;
    }
    for (char i : b) {
        if (i == '*') wild++;
        else frq2[(int)i-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (frq2[i] > frq1[i]) {
            cout << 'N' << endl;
            return 0;
        }
        wild -= (frq1[i]-frq2[i]);
    }
    if (wild >= 0) cout << 'A' << endl;
    return 0;       
}