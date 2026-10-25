#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    const ll MOD = 1000000007;

    while(t--) {
        int Q, K;
        cin >> Q >> K;

        vector<ll> a(1e6+1);
        vector<ll> sums(1e6+1);
        if (K==1) {
            sums[0] = 1; a[0] = 1;
            for (int i = 1; i <= 1e6+1; i++) {
                a[i] = (a[i-1]*2)%MOD; sums[i] = ((sums[i-1]%MOD) + (a[i])%MOD)%MOD;
            }
        }
        else {
            for(int i = 0; i < K; i++) {
                a[i] = 1;
                sums[i] = 1+i;
            }
            for(int i = K; i < 1e6+1; i++) {
                if (i-2*K+1<0) {a[i]=sums[i-K+1]; sums[i] = sums[i-1]+a[i]; continue;}
                a[i] = ((sums[i-K+1]%MOD)-(sums[i-2*K+1]%MOD)+MOD)%MOD; sums[i] = ((sums[i-1]%MOD)+(a[i]%MOD))%MOD;
            }
        }
        for (int i = 0; i < Q; i++) {
            int x, y;
            cin >> x >> y;
            if (x == 0) {cout << sums[y] << '\n'; continue;}
            cout << ((sums[y]%MOD) - (sums[x-1]%MOD) + MOD)%MOD << '\n';
        }
    }
    return 0;
}