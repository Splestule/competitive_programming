#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool sorted = false;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int counter = 0;
    while (sorted == false) {
        sorted = true;
        int minimum = INT_MAX;
        int min_pos = -1;
        for (int i = 0; i < n - counter; i++) {
            if (v[i+counter]<v[min(0, i+counter-1)]) {
                sorted = false;
            }
            if (v[i+counter] < minimum) {
                minimum = v[i+counter];
                min_pos = i+counter;
            }
        }
        if (min_pos == -1) {
            return 1;
        }
        v[min_pos] = v[counter];
        v[counter] = minimum;
        counter++;
    }

    for (int x : v) cout << x << " ";

    return 0;
}