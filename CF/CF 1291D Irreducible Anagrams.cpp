#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

string s;
vector<vector<int>> psum(26);

void solve() {
    int l, r;
    cin >> l >> r;
    --l;
    if (r-l == 1 || s[r-1] != s[l]){ cout << "Yes\n"; return;}
    int ccount = 0;
    for(int i=0; i<26; ++i){
        if (psum[i][r] - psum[i][l] > 0){
            if (ccount  == 2){
                cout << "Yes\n";
                return;
            }
            ++ccount;
        }
    }
    cout << "No\n";
}

signed main() {
    //surely in this case you just keep a prefix sum
    // but with another dimension for each letter...
    // O(n+q) surely this is trivial

    cin.tie(NULL) -> sync_with_stdio(false);


    cin >> s;
    int n = s.size();
    for(int i=0; i<26; ++i) {
        psum[i].resize(n+1);
        for(int j=0; j<n; ++j) psum[i][j+1] = psum[i][j]+(s[j]-'a' == i);
    }
    int q; cin >> q;
    while(q--){
        solve();
    }
}
