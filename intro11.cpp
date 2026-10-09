#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        const ll diff = b - a;
        a -= diff;
        b -= diff*2;
        if (a >= 0 && a % 3 == 0) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}