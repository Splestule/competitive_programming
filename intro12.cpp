#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    array<int, 128> cnt{};
    for (const unsigned char c : s) cnt[c]++;
    int o{};
    int pos{};
    const int size = s.size();
    string sol(size, ' ');
    for (int i = 0; i < 128; ++i) {
        if (cnt[i] == 0) continue;
        if (cnt[i] % 2 == 1) o++, sol[size/2] = static_cast<char>(i), cnt[i]--;
        int diff{};
        for (int j = 0; j < cnt[i]/2; ++j) {
            sol[pos+j] = static_cast<char>(i);
            sol[size-1-pos-j] = static_cast<char>(i);
            diff++;
        }
        pos += diff;
        if (o>1) {
            cout << "NO SOLUTION" << '\n';
            return 0;
        }
    }
    cout << sol << '\n';
    return 0;
}

