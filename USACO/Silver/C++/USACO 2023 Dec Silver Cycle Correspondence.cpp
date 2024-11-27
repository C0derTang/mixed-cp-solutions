#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, k;
    cin >> n >> k;
    
    vector<bool> out(n);

    vector<int> a(k);
    map<int, int> apos;
    for(int i=0; i<k; ++i){
        cin >> a[i]; --a[i];
        apos[a[i]] = i;
        out[a[i]] = true;
    }

    map<int, int> cwdist;
    map<int, int> ccwdist;

    vector<int> b(k);
    for(int i=0; i<k; ++i){
        cin >> b[i]; --b[i];
        out[b[i]] = true;
        if (apos.find(b[i]) == apos.end()) continue;
        int curcwd = i-apos[b[i]];
        if (curcwd < 0) curcwd += k;
        cwdist[curcwd]++;
    }
    reverse(b.begin(), b.end());
    for(int i=0; i<k; ++i){
        if (apos.find(b[i]) == apos.end()) continue;
        int curccwd = apos[b[i]]-i;
        if (curccwd < 0) curccwd += k;
        ccwdist[curccwd]++;
    }

    int ans=0;
    for(auto x: cwdist) ans = max(ans, x.second);
    for(auto x: ccwdist) ans = max(ans, x.second);
    for(auto x: out) ans += !x;
    cout << ans;
}
