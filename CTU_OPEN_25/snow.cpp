#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M, Q;
    cin >> M >> N >> Q;

    vector<vector<bool>> snow(M+1, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            char state;
            cin >> state;
            if (state == '*') {snow[M-1-i][j] = true;}
        }
    }

    vector<int> states(N, 0);

    queue<int> q;
    for (int i = 0; i < Q; i++) {
        int time;
        cin >> time;

        q.push(time);
    }

    int sum{};

    for (int i = 0; i < q.back()+1; i++) {
        if (i >= M) {
            while (!q.empty()) {
                cout << sum << '\n';
                q.pop();
            }
            break;
        }
        vector<bool> state(N, true);
        for (int j = 0; j < N; j++) {
            while (state[j]) {
                if (snow[min(states[j]+i, M)][j]) {
                    states[j]++;
                    sum++;
                    continue;
                }
                state[j] = false;
            }
        }
        if (i == q.front()) {
            cout << sum << '\n';
            q.pop();
        }
    }
    return 0;
}