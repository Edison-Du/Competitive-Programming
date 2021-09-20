#include <bits/stdc++.h>
using namespace std;

bool distinct(string y) {
    set<char> st;
    for (char i : y) st.insert((i));
    return st.size() == y.size();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int y;
    cin >> y;
    while(!distinct(to_string(++y)));
    cout << y << endl;
    return 0;
}