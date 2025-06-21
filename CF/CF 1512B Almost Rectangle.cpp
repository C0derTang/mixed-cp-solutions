#include <bits/stdc++.h>
using namespace std;

#define int long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

int binexp(int a, int b){
    int ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

int modinv(int a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


void solve(){
    int n; cin >> n;
    vector<string> grid(n);
    for(int i=0; i<n; ++i) cin >> grid[i];

    int x1=-1, y1=-1, x2=-1, y2=-1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if (grid[i][j] == '*'){
                if (x1==-1){
                    x1=i; y1=j;
                }else{
                    x2=i;y2=j;
                }
            }
        }
    }
    if(x1==x2){
        x2 = (x2+1)%n;
    }
    else if(y1==y2){
        y2 = (y2+1)%n;
    }

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if ((i==x1 && (j==y1 || j==y2)) || (i==x2 && (j==y1 || j==y2))){
                cout << '*';
            }else{
                cout << '.';
            }
        }
        cout << '\n';
    }
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