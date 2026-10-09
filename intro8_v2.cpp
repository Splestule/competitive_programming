#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;

    ll sum = (ll)n * (n+1)/2;
    if (sum % 2 != 0) {
        cout << "NO" << '\n';
        return 0;
    }
    ll budget = sum / 2;

    vector<int> l;
    vector<int> r;
    for (int i = 0; i < n; i++) {
        if (budget - n + i >= 0) {
                l.push_back(n-i);
                budget -= (n-i);
            }
        else {
            r.push_back(n-i);
        }
    }
    cout << "YES" << '\n';
    cout << l.size() << '\n';
    for (int j = 0; j < l.size(); j++) {
        cout << l[j] << ' ';
    }
    cout << '\n' << r.size() << '\n';
    for (int j = 0; j < r.size(); j++) {
        cout << r[j] << ' ';
    }
    return 0;
}
