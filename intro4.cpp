#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long> ns(n);
    long long moves = 0;
    for (int i = 0; i < n; i++) {
        cin >> ns[i];
    }
    for (int i = 1; i < n; i++) {
        while (ns[i - 1] > ns[i]) {
            ns[i]++;
            moves++;
        }
    }
    cout << moves << "\n";
    return 0;
}
