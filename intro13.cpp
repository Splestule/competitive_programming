#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string a(n,'0');

    int sign = 1;
    int counter = 0;
    for (int i = 0; i < (1 << n); i++) {
        cout << a << '\n';
        if (a[counter] == '0') { a[counter] = '1';}
        else a[counter] = '0';
        if (counter == n-1) sign = -1;
        else if (counter == 0) sign = 1;
        counter+=1*sign;
        }
    return 0;
}