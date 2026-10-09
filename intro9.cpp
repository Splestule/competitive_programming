#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    ll ans = 1;
    for (int i = 1; i <= t; i++) {
        ans = ((ans % (ll)(1e9+7))*2)%(ll)(1e9+7);
    }

    cout << ans << '\n';
    return 0;
}