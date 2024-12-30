#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    string s, e;
    cin >> s >> e;
    int n = s.size();
    // its not possible when 2 input nodes lead to multiple output nodes
    // 52 available chars, for swaps, an intermediary has to be available
    // only 1 intermediary is needed for all loops/cycles
    // each cycle needs 1 extra action
    //  benq orz orz orz

    map<char, char> changes;
    int ans=0;
    for(int i=0; i<n; ++i){
        if (changes.count(s[i]) && changes[s[i]] != e[i]){
            cout << "-1\n";
            return;
        }
        if (s[i] != e[i] && !changes.count(s[i])) ++ans;
        changes[s[i]] = e[i];
        
    }

    // is there a clean way for me to do cycle detection?
    set<char> seen;
    string ab = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (auto c: ab){
        if (seen.count(c) || !changes.count(c)) continue;
        char cur = c;
        while(changes.count(cur)){
            if (seen.count(cur)){
                if (changes[cur] == cur) break;
                if (changes.size() == 52){
                    cout << "-1\n";
                    return;
                }
                ++ans;
                break;
            }
            seen.insert(cur);
            cur = changes[cur];
        }
    }
    cout << ans << '\n';
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}