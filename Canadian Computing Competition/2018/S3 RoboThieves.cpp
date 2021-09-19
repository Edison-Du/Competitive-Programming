#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int dist[105][105], cam[105][105];
char grid[105][105];
vector<pii> cameras;
queue<pii> q;

void goCamera(int x, int y, int dx, int dy) {
    if (grid[y][x] == 'W') return;
    cam[y][x] = 1;
    goCamera(x+dx,y+dy,dx,dy);
}
void simCamera() {
    for (pii i : cameras) {
        for (int j = 0; j < 4; j++) {
            goCamera(i.second,i.first,dx[j],dy[j]);
        }
    }
}
pii conveyer(int x, int y, int d) {
    if (grid[y][x] == 'W' || (dist[y][x] <= d && dist[y][x] != -1)) return {-1,-1};
    if (grid[y][x] == '.') {
        if (cam[y][x]) return {-1,-1};
        else return {y, x};
    }
    dist[y][x] = d;
    if (grid[y][x] == 'L') return conveyer(x-1,y,d);
    if (grid[y][x] == 'R') return conveyer(x+1,y,d);
    if (grid[y][x] == 'U') return conveyer(x,y-1,d);
    if (grid[y][x] == 'D') return conveyer(x,y+1,d);
}
void bfs() {
    while (!q.empty()) {
        pii now = q.front();
        q.pop();
        if (cam[now.first][now.second]) continue;
        for (int i = 0; i < 4; i++) {
            int ny = now.first + dy[i];
            int nx = now.second + dx[i];
            if (grid[ny][nx] == 'W') continue;
            if (dist[ny][nx] == -1) {
                if (grid[ny][nx] == '.') {
                    if (!cam[ny][nx]) {
                        dist[ny][nx] = dist[now.first][now.second]+1;
                        q.push({ny, nx});
                    }
                } else if (grid[ny][nx] != 'C') {
                    pii nxt = conveyer(nx, ny, dist[now.first][now.second]);
                    if (nxt.first != -1) {
                        dist[nxt.first][nxt.second] = dist[now.first][now.second]+1;
                        q.push(nxt);
                    }
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dist,-1,sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                dist[i][j] = 0;
                q.push({i,j});
            }
            else if (grid[i][j] == 'C') cameras.push_back({i,j});
        }
    }
    simCamera();
    bfs();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                cout << dist[i][j] << endl;
            }
        }
    }
    return 0;       
}