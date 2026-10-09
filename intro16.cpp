#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<ll> v;
    ll sum{};
    for (int i{};i < t; i++) {
        ll n;
        cin >> n;
        v.push_back(n);
        sum += n;
    }

    ll best = LLONG_MAX;
    for (int mask = 0; mask < (1 << t); mask++) {
        ll a = 0;
        for (int i = 0; i < t; i++)
            if ((mask >> i) & 1) a += v[i];
        best = min(best, llabs(sum - 2 * a));
    }
    cout << best << '\n';
}