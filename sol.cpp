#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cerr << n << "\n";

    bool sorted = false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        int min_pos = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[min_pos]) min_pos = j;
        }
        swap(v[i], v[min_pos]);
    }

    for (const int x : v) cout << x << " ";

    return 0;
}