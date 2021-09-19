#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e6+5;

int n, m;
bool found, vis[MAX];
vector<int> adj[MAX];
void dfs (int s) {
    vis[s]=1;
    if (s==1) found=1;
    for (int i : adj[s]) {
        if (vis[i]||found) continue;
        dfs(i);
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int a; 
            cin >> a;
            adj[a].push_back(i*j);
        }
    }
    dfs(n*m);
    found ? cout << "yes":cout << "no";
    return 0;
}