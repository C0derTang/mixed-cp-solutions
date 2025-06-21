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
    int a,b;
    cin >> a >> b;
    string s; cin >> s;
    int l=0, r=a+b-1;
    while(l<r){
        if (s[l] == '?' && s[r] == '?'){
            ++l;
            --r;
            continue;
        }
        a -= (s[l]=='0') + (s[r]=='0');
        b -= (s[l]=='1') + (s[r]=='1');
        if (s[l] != '?' && s[l] != s[r]){
            s[r]=s[l];
            if(s[r] == '0') --a;
            else --b;
        }
        else if (s[r] != '?' && s[l] != s[r]){
            s[l]=s[r];
            if(s[r] == '0') --a;
            else --b;
        }

        ++l;
        --r;
    }


    l=0, r=s.size()-1;
    while(l<r){
        if (s[l] == '?' && s[r] == '?'){
            if (a>1){
                s[l]='0';
                s[r]='0';
                a -=2;
            }else{
                s[l]='1';
                s[r]='1';
                b -=2;
            }
        }
        ++l; --r;
    }

    if(s.size()%2){
        if (s[(s.size())/2]=='?') s[(s.size())/2] = (a>0 ? '0':'1');
        if (s[(s.size())/2] == '0') --a;
        else --b;
    }
    l=0, r=s.size()-1;
    bool val = true;
    while(l<=r){
        if (s[l] != s[r]) val=false;
        ++l; --r;
    }
    cout << (a==0 && b==0  && val ? s: "-1") << '\n';
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