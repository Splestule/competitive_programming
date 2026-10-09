#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int N, C;
        vector<int> W;
        cin >> N >> C;
        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            W.push_back(temp);
        }
        sort(W.begin(), W.end());

        int i{};
        int j = W.size() - 1;

        int out{};
        while (i<=j) {
            if (W[i] == W[j]) {out++;break;}
            if (W[i]+W[j]<=C) {i++; j--;}
            else {j--;}
            out++;
        }
        cout << out << '\n';
    }
    return 0;
}