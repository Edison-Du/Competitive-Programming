#include <bits/stdc++.h>
using namespace std;

int n;
string arr[35];
set<pair<string,string>> st;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (a > arr[i]) st.insert({a, arr[i]});
        else st.insert({arr[i], a});
    }
    st.size()*2 == n? cout << "good" : cout << "bad";
    return 0;       
}