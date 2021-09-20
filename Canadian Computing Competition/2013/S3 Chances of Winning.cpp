#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int t, g;
vector<int> score(5);
vector<pii> games = {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};

int solve(int idx, int state, vector<int> vec) {
    int ret = 0;
    if (idx > games.size()) {
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i] >= vec[t] && i != t) ret = 1;
        }
        return !ret;
    } else if (idx > 0) {
        if (state == 0) vec[games[idx-1].first] += 3;
        else if (state == 1) vec[games[idx-1].second] += 3;
        else {
            vec[games[idx-1].first]++;
            vec[games[idx-1].second]++;
        }
    }
    for (int i = 0; i < 3; i++) {
        ret += solve(idx+1, i, vec);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> t >> g;
    while(g--) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        if (sa > sb) score[a] += 3;
        else if (sb > sa) score[b] += 3;
        else {
            score[a]++; 
            score[b]++;
        }
        games.erase(find(games.begin(), games.end(), pii(a, b)));
    }
    cout << solve(0, 0, score)/3 << endl;
    return 0;       
}