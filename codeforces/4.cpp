#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        int temp;
        for (int i = 0; i < n; i++) {cin >> temp; a.push_back(temp);}
        sort(a.begin(), a.end());

        vector<int> v;
        int r = n-1;
        int l = n-1;
        int same{};
        while (l >= 0) {
            if (l+1<n && a[l] == a[l+1]) same++; else same = 0;
            if (a[l+1]>a[l]) {
                v.push_back(r-l);
                if (same != 0) v.push_back(r-l-same);
            }
            if (l == 0) {
                v.push_back(r+1);
                if (same != 0) v.push_back(r+1-same);
            }
            if (l+1==n || a[l+1]-a[l]<=k) l--;
            else r--;
        }
        bool ok = false;
        for (int p : v) {
            if (p % 2 == 0) {
                ok = true;
                break;
            }
        };
        if (ok) {cout << "YES" << '\n';} else {cout << "NO" << '\n';}
    }
    return 0;
}