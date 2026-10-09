#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    int n{};

    while (t--) {
        n++;
        const ll k = pow(n, 2);
        cout << (k*(k-1))/2 - 4*k + 12*n - 8 << '\n';
    }
}