#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    map<int, vector<pair<int, int>>> grooves;
    for (int i = 0; i < M; i++) {
        int x_1, x_2, y;
        cin >> x_1 >> y >> x_2 >> y;
        x_1--; x_2--; y--;
        grooves[y].push_back(make_pair(x_1, x_2));
    }

    vector<int> pos(N); for (int i = 0; i < N; i++) pos[i] = i+1;
    vector<int> out(N); for (int i = 0; i < N; i++) out[i] = i+1;

    for (pair<const int, vector<pair<int, int>>> p : grooves) {
        for (int i = 0; i < static_cast<int>(p.second.size()); i++) {
            int temp = pos[p.second[i].first];
            pos[p.second[i].first] = pos[p.second[i].second];
            pos[p.second[i].second] = temp;

            temp = out[pos[p.second[i].first]-1];
            out[pos[p.second[i].first]-1] = out[pos[p.second[i].second]-1];
            out[pos[p.second[i].second]-1] = temp;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << out[i] << '\n';
    }
    return 0;
}