#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void BFS(bool& ok, int now, pair<int, int> pos, const vector<vector<int>>& grid, const pair<int,int>& target, queue<pair<int,int>>& q, vector<vector<bool>>& visited, const int& time, const int& N, queue<int>& times) {
    if (grid[pos.first][pos.second] >= time + now && visited[pos.first][pos.second] == false) {
        visited[pos.first][pos.second] = true;
        if (pos == target) ok = true;
        else {
            if (pos.first + 1 < N) {q.push({pos.first + 1, pos.second}); times.push(now+1);}
            if (pos.second + 1 < N) {q.push({pos.first, pos.second + 1}); times.push(now+1);}
            if (pos.first - 1 >= 0) {q.push({pos.first - 1, pos.second}); times.push(now+1);}
            if (pos.second - 1 >= 0) {q.push({pos.first, pos.second - 1}); times.push(now+1);}
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cerr << "Case #" << t << ": " << '\n';
        int N, x, y;
        cin >> N >> x >> y;
        x--;y--;
        int max_height = 0;
        vector<vector<int>> grid(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
                if (grid[i][j] > max_height) max_height = grid[i][j];
            }
        }

        int r = max_height;
        int l = 0;
        int time;
        int ans;

        bool possible = false;

            do {
                time = l + ((r-l+1)/2);
                vector<vector<bool>> visited(N, vector<bool>(N, false));
                queue<pair<int, int>> q;
                queue<int> times;
                q.push({N/2, N/2});
                times.push(0);
                bool ok = false;
                while (!q.empty() && !ok) {
                    auto pos = q.front();
                    auto now = times.front();
                    BFS(ok, now, pos, grid, {y,x}, q, visited, time, N, times);
                    q.pop();
                    times.pop();
                }
                if (!ok) {
                    r = l + ((r-l+1)/2)-1;
                }
                else {
                    l = l + ((r-l+1)/2);
                    possible = true;
                    ans = time;
                    if (l==r) break;
                }
            } while (r >= l);

        if (!possible) {cout << -1 << '\n'; continue;}
        cout << ans << '\n';
    }
}