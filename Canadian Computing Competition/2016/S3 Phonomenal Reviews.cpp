#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e5+5;

int n, m, r, edges, far, dis, pho[MAX], prune[MAX];
vector<int> adj[MAX];

bool pruneTree(int s, int p) {
    bool good = pho[s];
    for (int i : adj[s]) {
        if (i != p) {
            good |= pruneTree(i, s);
        }
    }
    if (good) prune[s] = 1;
    else edges--;
    return good;
}
void dfs(int s, int p, int d) {
    if (d > dis) {
        dis = d, far = s;
    }
    for (int i : adj[s]) {
        if (i != p && prune[i]) {
            dfs(i, s, d+1);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    edges = n-1;
    for (int i = 0; i < m; i++) {
        cin >> r;
        pho[r] = 1;
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    pruneTree(r, -1);
    dfs(r, -1, 0);
    dfs(far, -1, 0);
    cout << 2*edges-dis << endl;
    return 0;       
}