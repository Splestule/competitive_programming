#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(int n, char from, char to, char aux) {
    if (n == 0) return;
    solve(n-1, from, aux, to);
    cout << from << " " << to << '\n';
    solve(n-1, aux, to, from);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout << (1 << n) - 1 << '\n';
    solve(n, '1', '3', '2');
    return 0;
}