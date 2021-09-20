#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)2e5+5;
#define INF 0x3f3f3f3f

int n, w, d, station[MAX], walkDist[MAX], vis[MAX];
vector<int> revAdj[MAX];
multiset<int> ans;
void bfs () {
    memset(walkDist, INF, sizeof(walkDist));
    queue<int> q;
    q.push(n);
    walkDist[n] = 0;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        vis[now] = 1;
        for (int i : revAdj[now]) {
            if (vis[i]) continue;
            vis[i] = 1;
            walkDist[i] = walkDist[now]+1;
            q.push(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> w >> d;
    for (int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;
        revAdj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        cin >> station[i];
    }
    bfs();
    for (int i = 0; i < n; i++) {
        ans.insert(i+walkDist[station[i]]);
    }
    for (int i = 0; i < d; i++) {
        int x, y; 
        cin >> x >> y;
        x--; y--;
        ans.erase(ans.find(x+walkDist[station[x]]));
        ans.erase(ans.find(y+walkDist[station[y]]));
        swap(station[x], station[y]);
        ans.insert(x+walkDist[station[x]]);
        ans.insert(y+walkDist[station[y]]);
        cout << *ans.begin() << endl;
    }
    return 0;
}