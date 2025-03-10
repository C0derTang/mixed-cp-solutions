#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD(a, b) ((((a) % (b)) + (b)) % (b))

const int dulo = 998244353;

ll binexp(ll a, ll b){
    ll ret = 1;
    while (b>0){
        if (b&1) ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

ll modinv(ll a){
    return binexp(a, dulo-2);
}

bool cbs(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

vector<vector<int>> factors(100001);
void precomp(){
    for(int i=1; i<100001; ++i){
        for(int j=i; j<100001; j+=i){
            factors[j].push_back(i);
        }
    }
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    map<char, int> freq;
    for(auto c: s) ++freq[c];

    map<char, set<int>> pos;
    for(int i=0; i<n; ++i) pos[s[i]].insert(i);

    int ans = n;
    string anss = "";
    for(auto f: factors[n]){
        if (n/f > 26) continue;
        string ab = "abcdefghijklmnopqrstuvwxyz";

        vector<pair<int, char>> poss;
        for(auto x: ab)poss.push_back({min(f, freq[x]), x});
        sort(poss.begin(), poss.end(), greater<pair<int, char>>());

        int correct = 0;
        vector<char> good;
        for(int i=0; i<n/f; ++i){
            correct += poss[i].first;
            good.push_back(poss[i].second);
        }
        string temp=s;
        int curans=n-correct;
        
        set<char>goodset(good.begin(), good.end());
        map<char, int> used;
        for(auto x: good) used[x] = 0;
        vector<bool> keep(n);
        for(int i=0; i<n; ++i){
            if (goodset.count(s[i]) && used[s[i]] < f){
                keep[i] = true;
                ++used[s[i]];
            }
        }

        map<char, int> need;
        for(auto x: good) need[x] = f-used[x];

        for(int i=0; i<n; ++i){
            if (!keep[i]){
                for(auto x: good){
                    if(need[x] > 0){
                        temp[i] = x;
                        --need[x];
                        break;
                    }
                }
            }
        }
        
        if (curans < ans){
            ans = curans;
            anss = temp;
        }
    }
    cout << ans << '\n' << anss<< '\n';
}

signed main() {
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);

    cin.tie(NULL) -> sync_with_stdio(false);

    precomp();
    
    int t; cin >> t;
    while(t--){
        solve();
    }
}