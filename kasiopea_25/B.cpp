#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int N;
    cin >> N;
    vector<int> carts(N);
    int streak{};
    ll count{};
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (c == 'V') {streak++; carts[i] = streak; count++;} else {streak = 0;}
    }
    vector<ll> prefix(N+1, 0);
    vector<ll> vals(N);
    ll pref{};
    for (int i = 0; i < N; i++) {
        ll concentration;
        cin >> concentration;
        pref+=concentration;
        prefix[i+1] = pref;
        vals[i] = concentration;
    }
    ll total{};

    for (int i = 0; i < N-1; i++) {
        if (carts[i] > 0 && carts[i+1] == 0) {
            ll mn = LLONG_MAX;
            for (int j = 0; j <= carts[i]; j++) {
                mn = min(mn, vals[i-carts[i]+1+j]);
            }
            total+=prefix[i+1+1]-prefix[i-carts[i]+1]-mn;
        }
    }
    cout << total/count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}