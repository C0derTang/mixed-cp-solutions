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
    vector<pair<int, int>> w(n);
    for(int i=0; i<n; ++i) cin >> w[i].first >> w[i].second;

    map<int, int> same;
    for(auto x: w) if (x.first == x.second) ++same[x.first];

    vector<pair<int, int>> itv;
    for(auto x: same){
        if (!itv.empty() && x.first == itv.back().second+1){
            ++itv[itv.size()-1].second;
        }else{
            itv.push_back({x.first, x.first});
        }
    }

    
    for(auto x: w){
        if (x.first == x.second && same[x.first] > 1){
            cout << '0';
        }else if (x.first == x.second && same[x.first] == 1){
            cout << '1';
        }else{
            bool val = true;
            for(auto y: itv){
                if (x.first >= y.first && x.second <= y.second){
                    val = false;
                    break;
                }
            }
            cout << val;
        }
    }
    cout << '\n';
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