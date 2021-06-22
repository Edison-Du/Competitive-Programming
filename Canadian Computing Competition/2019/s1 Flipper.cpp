#include <bits/stdc++.h>
using namespace std;

int h, v;
char c;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (cin >> c) {
        c == 'H' ? h++ : v++;
    }
    if ((h&1)&&(v&1)) {
        cout << "4 3" << endl << "2 1" << endl; 
    }
    else if (h&1) {
        cout << "3 4" << endl << "1 2" << endl; 
    } 
    else if (v&1) {
        cout << "2 1" << endl << "4 3" << endl; 
    } 
    else {
        cout << "1 2" << endl << "3 4" << endl; 
    }
    return 0;       
}