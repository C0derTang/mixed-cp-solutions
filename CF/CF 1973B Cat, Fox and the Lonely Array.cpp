#include <bits/stdc++.h>

using namespace std;

#define ll long long

void bin(int n)
{
    cout << (n & 1);
    if (n > 1)
        bin(n >> 1);
}

void solve(){
    int n; 
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    
    int l = 1, r = n;
    while (l < r){
        int k = (l + r) / 2;

        int lmao = 0;
        bool valid = true;
        vector<int> bitfreq(32);
        for(int i = 0; i < k; ++i) {
            for (int j = 0; j < 32; ++j){
                bitfreq[j] += (a[i] >> j) & 1;
            }
            lmao |= a[i];
        }
        
        for(int i = k; i < n; ++i){
            int newlmao = lmao;
            for (int j = 0; j < 32; ++j){
                bitfreq[j] -= (a[i - k] >> j) & 1;
                bitfreq[j] = max(bitfreq[j], 0);
                if (bitfreq[j] == 0) newlmao &= ~(1 << j);
            }
            
            newlmao |= a[i];
            for (int j = 0; j < 32; ++j){
                bitfreq[j] += (a[i] >> j) & 1;
            }

            if (newlmao != lmao) {
                valid = false;
                break;
            }
        }

        if (valid){
            r = k;
        } else {
            l = k + 1;
        }
    }

    cout << l << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; 
    cin >> t;
    while(t--){
        solve();
    }
}
