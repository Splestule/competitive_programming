#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, x;
        cin >> a >> b >> x;
        ll steps{};
        while (true) {
            bool end = true;
            if (llabs(a-b)>llabs(a/x-b)) end = false, a /= x, steps++;
            else if (llabs(a-b)>llabs(b/x-a)) end = false, b /= x, steps++;
            else if (llabs(a-b)>llabs(a/x-b/x) && 1<llabs(a-b)-llabs(a/x-b/x)) end = false, a /= x, b /= x, steps+=2;
            if (end || a == b) break;
        }
        cout << steps + llabs(a-b) << '\n';
    }
    return 0;
}