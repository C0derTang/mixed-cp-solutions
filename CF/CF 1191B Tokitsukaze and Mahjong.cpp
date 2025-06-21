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
    //sliding window orz? surely
    // 001 is good
    // 100 is bad
    // 101 is good
    // 010 is good
    //0111111 is bad
    // 101111111 is bad
    //010000 is bad
    // 1000000 is bad
    // 00000001 is good
    // 1111110 is good
    // for every one we can count//
    //0101 is good bc 0101 -> 001 -> 01 -> 1

    // for every occurence of 01 count number of leading zeros (+1 if following is a zero)
    // for every occurence of 10 count number of leading ones (+1 if if following is a one)

    // or can we dp
    // 1001
    // 134 

    //0100
    // -1=7?


    //0100101
    //01224

    //wait
    //im retarded

    // wait wait
    // 1=1
    // 0=1
    // 00=2
    // 01=3
    // 10=3
    // 11=2
    // 000=3
    // 001=5
    // 010=6
    // 011=

    // wait im retarded we can just take all indices and subtract the number of indices with contiguous ones
    // complement lmao im actually trash

    int n; cin >> n;
    string s; cin >> s;
    int ans=n*(n+1)/2;

    char cur = s[0];
    int len=0, l=0;
    int i;
    for(i=0; i<n; ++i){
        if(s[i]==cur){
            ++len;
        }else{
            ans -= len*(len-1)/2;
            if(len>1) ans -= l*(len-1);
            l=i;
            cur = s[i];
            len=1;
        }
    }

    ans -= len*(len-1)/2;
    if(len>1) ans -= l*(len-1);
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