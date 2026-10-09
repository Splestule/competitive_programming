#include <bits/stdc++.h>
using namespace std;
using ll = long long;



void BFS(vector<int> from, vector<int> pos, vector<vector<int>>& dp, const vector<vector<int>>& grid, int N, queue<vector<int>>& q, queue<vector<int>>& froms, vector<vector<vector<int>>>& directions, vector<vector<int>>& time) {
    if (grid[pos[0]][pos[1]] - dp[from[0]][from[1]]+1 >= 0 && (min(grid[pos[0]][pos[1]],dp[from[0]][from[1]]) > dp[pos[0]][pos[1]] || (min(grid[pos[0]][pos[1]],dp[from[0]][from[1]]) == dp[pos[0]][pos[1]])) && time[from[0]][from[1]] > time[pos[0]][pos[1]]) {
        dp[pos[0]][pos[1]] = dp[from[0]][from[1]];
        time[pos[0]][pos[1]] = time[from[0]][from[1]]+1;
        directions[pos[0]][pos[1]][0] = pos[0]-from[0]; directions[pos[0]][pos[1]][1] = pos[1]-from[1];
        int k{};
        for (int i = -1; i < 2; i += 2) {
            if (pos[0]+i<N && 0<=pos[0]+i) {q.push({pos[0]+i, pos[1]}); k++;}
            if (pos[1]+i<N && 0<=pos[1]+i) {q.push({pos[0], pos[1]+i}); k++;}
        }
        for (int i = 0; i < k; i++) {froms.push({pos[0], pos[1]});}
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
        queue<vector<int>> q;
        queue<vector<int>> froms;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        vector<vector<int>> time(N, vector<int>(N, INT_MAX));
        time[N/2][N/2] = 0;
        vector<vector<int>> grid(N, vector<int>(N, 0));
        vector<vector<vector<int>>> directions(N, vector<vector<int>>(N, {0, 0}));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }
        vector<int> start = {N/2,N/2};
        q.push({N/2+1,N/2}); froms.push(start);
        q.push({N/2-1,N/2}); froms.push(start);
        q.push({N/2,N/2+1}); froms.push(start);
        q.push({N/2,N/2-1}); froms.push(start);
        dp[N/2][N/2] = grid[N/2][N/2];
        while (!q.empty()) {
            cerr << "length: " << q.size() << '\n';
            const auto to = q.front();
            const auto from = froms.front();
            BFS(from, to, dp, grid, N, q, froms, directions, time);
            q.pop();
            froms.pop();
        }
        if (dp[x][y] == INT_MAX) {cout << -1 << '\n'; continue;}
        int w = x;
        int z = y;
        int ans = INT_MAX;
        while (w != N/2 && z != N/2) {
            cerr << "w: " << w << " z: " << z << '\n';
            ans = min(ans, grid[w][z]-dp[w][z]);
            int temp = directions[w][z][0]; z -= directions[w][z][1];
            w -= temp;
        }
        cout << ans << '\n';
    }
}