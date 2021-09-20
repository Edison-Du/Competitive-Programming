#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

struct edge{
    int node, w, d;
};
struct cmpEdge {
    bool operator()(edge const&a, edge const&b) {
        return a.w > b.w;
    }
};
int k, n, m, A, B, dist[2005][205];
vector<edge> adj[2005];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    memset(dist, INF, sizeof(dist));
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, t, h;
        cin >> a >> b >> t >> h;
        adj[a].push_back({b, t, h});
        adj[b].push_back({a, t, h});
    }
    cin >> A >> B;
    priority_queue<edge, vector<edge>, cmpEdge> pq;
    pq.push({A, 0, 0});
    while (!pq.empty()) {
        auto now = pq.top(); 
        pq.pop();
        if (now.node == B) break;
        if (dist[now.node][now.d] < now.w) continue;
        for (auto s : adj[now.node]) {
            int dmg = s.d + now.d, time = s.w + now.w;
            if (dmg >= k) continue;
            if (dist[s.node][dmg] > time) {
                dist[s.node][dmg] = time;
                pq.push({s.node, time, dmg});
            }
        }
    }
    int ans = INF;
    for (int i = 0; i < k; i++) ans = min(ans, dist[B][i]);
    ans == INF ? cout << -1 : cout << ans;
    return 0;
}