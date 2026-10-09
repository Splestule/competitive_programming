#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        set trades;
        for(int i = 0; i < M; i++) {
            int A, B, C;
            cin >> A >> B >> C;
            vector<int> v;
            v.push_back(A);
            v.push_back(B);
            v.push_back(C);
            trades.insert(v);
        }
        vector<int> visited;
        for (A, B : trades) {
            visited.push_back(A);
            visited.push_back(B);
            cout << A << " " << B << '\n';
        }
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            if (trades.find(i : C))
                for (int j = 0; j < N; j++) {
                    if (!visited[j _at pos i]) cout << i << " " << j << '\n'; break;
                }
            else {
                if (i == 0) cout << i << " " << i+1 << '\n';
                else cout << i << " " << 1 << '\n';
            }
        }
    }
    return 0;
}