#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll zeroes{};
    ll handoff{};
    while (n-handoff >= 5) {
        ll p = 1;
        int add{};
        while (p*5<=n-handoff) {
            add*=5;
            add+=1;
            p*=5;
        }
        zeroes += add;
        handoff += p;
    }
    cout << zeroes << '\n';
    return 0;
}