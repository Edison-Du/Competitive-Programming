#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)2e5+5;
const int MAXZ = 20;

int gcd(int a, int b) {
    if (b) return gcd(b, a%b);
    else return a;
}

int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}

struct segmentTreeGCD {
    int sz;
    vector<int> vals;
    void init (int n) {
        sz = n;
        vals.assign(2*n, 0);
    }
    void build (vector<int> &arr) {
        for (int i = 0; i < sz; i++) vals[i+sz] = arr[i];
        for (int i = sz-1; i > 0; i--) vals[i] = gcd(vals[2*i], vals[2*i+1]);
    }
    void set (int p, int v) {
        vals[p += sz] = v;
        while (p /= 2) vals[p] = gcd(vals[2*p], vals[2*p+1]);
    }
    int get (int l, int r) {
        int ret = 0;
        l += sz, r += sz;
        for (; l < r; l /= 2, r /= 2) {
            if (l&1) ret = gcd(ret, vals[l++]);
            if (r&1) ret = gcd(ret, vals[--r]);
        }
        return ret;
    }
};

int n, m, psa[MAXN][MAXZ];
int x[MAXN], y[MAXN], z[MAXN];
vector<int> arr(MAXN);
segmentTreeGCD st;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i] >> z[i];
        psa[x[i]][z[i]]++;
        psa[y[i]+1][z[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        arr[i] = 1;
        for (int j = 0; j < MAXZ; j++) {
            psa[i][j] += psa[i-1][j];
            if (psa[i][j]) {
                arr[i] = lcm(arr[i], j);
            }
        }
    }
    st.init(n+1);
    st.build(arr);
    for (int i = 0; i < m; i++) {
        if (st.get(x[i], y[i]+1) != z[i]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;       
}