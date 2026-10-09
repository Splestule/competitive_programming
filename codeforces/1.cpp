#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int max{};
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            if (temp < min) min = temp;
            if (temp > max) max = temp;
        }
        cout << max - min + 1 << "\n";
    }
    return 0;
}