#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> ns(n-1);
    for (int i = 0; i < n - 1; i++) {
        cin >> ns[i];
    }
    sort(ns.begin(), ns.end());
    if (n-2 == 0) {
        if (ns[0] == 1) {
            cout << 2;
            return 0;
        }
        cout << 1;
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        if (ns[i+1] - 1 != ns[i]) {
            cout << ns[i] + 1;
            return 0;
        }
    }
}
