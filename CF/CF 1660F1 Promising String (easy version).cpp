#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define pii pair<int, int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back
#define F first
#define S second

bool cbs(pii a, pii b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    
    vi pp(n + 1, 0), mp(n + 1, 0);
    
    FL(i, 0, n) {
        pp[i + 1] = pp[i] + (s[i] == '+');
        mp[i + 1] = mp[i] + (s[i] == '-');
    }
    
    int ans = 0;
    FL(i, 0, n) {
        FL(j, i + 1, n + 1) {
            int pc = pp[j] - pp[i];
            int mc = mp[j] - mp[i];
            
            if (pc == mc) {
                ++ans;
            } else if (mc > pc && (2*mc - 2*pc) % 3 == 0) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
