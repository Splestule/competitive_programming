#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (ll sum = n * (n + 1) / 2; sum % 2 == 0) {
        if (n % 4 == 0) {
            cout << "YES" << "\n";
            cout << (n / 2) << '\n';
            for (int i = 0; i < n/4; i++) {
                cout << i+1 << " " << n-i << " ";
            }
            cout << "\n" << (n / 2) << '\n';
            for (int i = 0; i < n/4; i++) {
                cout << i + 1 + n/4 << " " << (n*3)/4 - i << " ";
            }
            return 0;
        }
        else {
            cout << "YES" << "\n";
            int p_1{};
            int p_2{};
            const int middle = (n / 2) + 1;
            for (int i = 0; i < n/2; i++) {
                if (i+1 + middle == n - i) {
                    p_1 = i+1;
                    p_2 = n-i;
                }
            }
            cout << ((n / 2)+1) << '\n';
            for (int i = 0; i < n/4; i++) {
                if (i+1 != p_1) {
                    cout << i+1 << " " << n-i << " ";
                }
            }
            cout << p_1 << " " << middle << "\n";
            cout << (n / 2) << '\n';
            int k{};
            for (int i = 0; i < n/4; i++) {
                if (k + i + n/4 + 1 != p_1) {
                    cout << 1 + k + i + n/4 << " " << (n*3)/4 - i - k + 1 << " ";
                }
                else {
                    k++;
                    cout << 1 + k + i + n/4 << " " << (n*3)/4 - i - k + 1 << " ";
                }
            }
            cout << p_2 << "\n";
            return 0;

        }
    }
    else {
        cout << "NO" << '\n';
        return 0;
    }
}