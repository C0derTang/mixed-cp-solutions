#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    int n; cin >> n;
    if(n<5){
        cout <<"-1\n";
        return;
    }
    for(int i=7; i<=n; i+=2) cout << i << ' ';
    cout << "1 3 5 4 2 ";
    for(int i=6; i<=n; i+=2) cout << i << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    int t; cin >> t;
    while(t--){
        solve();
    }
}