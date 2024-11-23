#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int n, m, k;
    cin >> n >> m >> k;
    map<int, int> cows;
    for(int i=0; i<n; ++i){
        int x,y;
        cin >> x >> y;
        cows[-x] += y;
    }

    map<int, int> available;
    available[10000000000] = m;

    int ans = 0;
    while(true){
        auto it = cows.lower_bound(-available.rbegin()->first+k);
        if (it == cows.end()) break;

        int move = min(it->second, available.rbegin()->second);

        ans += move;
        available[-it->first] += move;
        cows[it->first] -= move;
        available[available.rbegin()->first] -= move;
        
        if(it->second == 0) cows.erase(it);
        if (available.rbegin()->second == 0) available.erase(available.rbegin()->first);
        

    }
    cout << ans;
}
