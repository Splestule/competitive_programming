#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<ll, vector<int>> byX, byY;
    vector<ll> xs, ys;

    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        xs.push_back(x);
        ys.push_back(y);
        byX[x].push_back(i);
        byY[y].push_back(i);
    }

    vector<bool> visited(N, false);
    int output = -1;

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        queue<pair<ll,ll>> q;
        q.push(make_pair(xs[i],ys[i]));
        visited[i] = true;

        while (!q.empty()) {
            ll currx = q.front().first;
            ll curry = q.front().second;
            q.pop();
            for (int j = 0; j < static_cast<int>(byX[currx].size()); j++) {
                int pos = byX[currx][j];
                if (visited[pos]) continue;
                q.push(make_pair(xs[pos], ys[pos]));
                visited[pos] = true;
            }
            byX[currx].clear();
            for (int j = 0; j < static_cast<int>(byY[curry].size()); j++) {
                int pos = byY[curry][j];
                if (visited[pos]) continue;
                q.push(make_pair(xs[pos], ys[pos]));
                visited[pos] = true;
            }
            byY[curry].clear();
        }
        output++;
    }
    cout << output << '\n';
    return 0;
}