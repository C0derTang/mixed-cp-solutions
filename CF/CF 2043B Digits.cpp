#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

void solve() {
    ll n, d;
    cin >> n >> d;
    cout << "1 ";
    //if sum of digits %3 == 0
    // 
    if (n>=3 || d == 3 || d == 6 || d == 9) cout << "3 ";
    if(d == 5) cout << "5 ";
    if (n >= 7 || d==7 || n>=3){
        cout << "7 ";
    }
    if (n>=6 || d==9 || (n>=3 && (d==3 || d==6))) cout << "9 ";
    cout << '\n';
}

signed main() {
    cin.tie(NULL) -> sync_with_stdio(false);
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}
