#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<ll> v = {1};
    while (t--) {
        ll y, x;       
        cin >> x >> y;

        const ll level = max(y, x);
        const ll diagonal = level * level - level + 1;

        const ll sign = (level % 2 == 0) ? 1 : -1;
        cout << diagonal + sign*(x - y) << '\n';
    }
    return 0;
}