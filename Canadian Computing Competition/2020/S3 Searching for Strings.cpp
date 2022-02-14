#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int MAXN = (int)2e5+5;
const ll MOD = (ll)1e9+7;
const ll PRIME_A = 131;
const ll PRIME_B = 133;

string n, h;
int goodFreq[26], tempFreq[26], flag;
ll pow1[MAXN], pow2[MAXN];
ll hash1[MAXN], hash2[MAXN];
set<pll> ans;

ll subHash(int i, int j, ll pow[], ll hash[]) {
    ll ret = hash[j];
    if (i) ret = (((ret - hash[i-1] * pow[j-i+1]) % MOD) + MOD) % MOD;
    return ret;
}

void goodSub(int i, int j) {
    ll h1 = subHash(i, j, pow1, hash1);
    ll h2 = subHash(i, j, pow2, hash2);
    ans.insert({h1, h2});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;

    // Preprocess hash and pow
    pow1[0]  = pow2[0]  = 1;
    hash1[0] = hash2[0] = h[0];

    for (int i = 1; i < h.size(); i++) {
        pow1[i]  = (pow1[i-1] * PRIME_A) % MOD;
        pow2[i]  = (pow2[i-1] * PRIME_B) % MOD;
        hash1[i] = (hash1[i-1] * PRIME_A + h[i]) % MOD;
        hash2[i] = (hash2[i-1] * PRIME_B + h[i]) % MOD;
    }

    // Initial frequencies
    for (int i = 0; i < n.size(); i++) {
        goodFreq[(int)(n[i]-'a')]++;
        tempFreq[(int)(h[i]-'a')]++;
    }

    for (int i = 0; i < 26; i++) flag += (goodFreq[i] == tempFreq[i]);
    if (flag == 26) goodSub(0, n.size()-1);

    // Sliding window check for permutation
    for (int i = 0; i + n.size() < h.size(); i++) {
        int c1 = (int)(h[i]-'a');
        int c2 = (int)(h[i+n.size()]-'a');

        flag -= (tempFreq[c1] == goodFreq[c1]) + (tempFreq[c2] == goodFreq[c2]);
        tempFreq[c1]--; 
        tempFreq[c2]++;
        flag += (tempFreq[c1] == goodFreq[c1]) + (tempFreq[c2] == goodFreq[c2]);

        if (flag == 26) goodSub(i+1, i+n.size());
    }

    cout << ans.size() << endl;
    return 0;
}