#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int MAX = (int)1e5+5;

struct ed {
    int u, v, c, t;
    bool operator<(const ed& y) const { return c < y.c; }
};

struct dsu{
    int link[MAX], sz[MAX];
    void init(int n) {
        for (int i = 1; i <= n; i++) link[i]=i, sz[i]=1;
    }
    int find(int x) {
        while (x != link[x]) x = link[x];
        return x;
    }
    bool unite(int a, int b) {
        int e = find(a), f = find(b);
        if (e==f) return 0;
        if (sz[e] < sz[f]) swap(e, f);
        sz[e] += sz[f];
        link[f] = e;
        return 1;
    }
} planet, city;

ll n, m, p, q, en, nc;
vector<ed> edges;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> p >> q;
    for (int i = 0; i < p; i++) {
        int a, b, c; cin >> a >> b >> c;
        en += c * n; edges.push_back({a, b, c, 0});
    }
    for (int i = 0; i < q; i++) {
        int x, y, z; cin >> x >> y >> z;
        en += z * m; edges.push_back({x, y, z, 1});
    }
    sort(edges.begin(), edges.end());
    planet.init(n); city.init(m);
    for (auto &i : edges) {
        if (i.t) { 
            if (planet.unite(i.u, i.v)) {
                n--;
                nc += i.c * m;
            }
        }
        else { 
            if (city.unite(i.u, i.v)) {
                m--;
                nc += i.c * n;  
            }
        }
    }
    cout << en - nc << endl;
    return 0; 
}