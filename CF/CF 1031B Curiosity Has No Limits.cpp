#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define FL(i, a, b) for(int i=a; i<b; ++i)
#define PB push_back

bool isval(int a, int b, int t1, int &t2){
    FL(pt2, 0, 4){
        if((t1 | pt2) == a && (t1 & pt2) == b){
            t2 = pt2;
            return true;
        }
    }
    return false;
}
void solve() {
    int n; cin >> n;
    vi t(n), a(n-1), b(n-1);
    FL(i,0,n-1) cin >> a[i];
    FL(i,0,n-1) cin >> b[i];

    bool found = false;
    for(int i=0; i<4 && !found; ++i){
        t[0] = i;
        bool val = true;
        for(int j=0; j<n-1 && val; ++j){
            val = isval(a[j], b[j], t[j], t[j+1]);
        }
        if (val){
            found = true;
            break;
        }
    }
    if (found){
        cout << "YES\n";
        for (auto x: t) cout << x << ' ';
    }else{
        cout << "NO";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
