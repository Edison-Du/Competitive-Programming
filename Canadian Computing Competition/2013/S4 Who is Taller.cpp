#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e6+5;

int n, m, p, q;
bool vis[MAX];
vector<int> adj[MAX];
bool dfs (int cur, int target) {
    if (cur == target) return 1;
    else if (vis[cur]) return 0;
    vis[cur] = 1;
    bool good = 0;
    for (int i : adj[cur]) {
        good |= dfs(i, target);
    }
    return good;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    cin >> p >> q;
    if (dfs(p, q)) cout << "yes" << endl;
    else if (dfs(q, p)) cout << "no" << endl;
    else cout << "unknown" << endl;
    return 0;       
}