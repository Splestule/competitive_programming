#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<set<pair<int,int>>> visited;

int solve(set<pair<int,int>>& reserved, set<pair<int,int>>& queens) {
    if (visited.contains(queens)) return 0;
    visited.insert(queens);
    if (size(queens) == 8) return 1;
    int sols{};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (reserved.contains({i, j})) continue;
            queens.insert({i, j});
            reserved.insert({i, j});
            vector<pair<int,int>> before;
            for (int k = 1; k < 8; k++) {
                if (j+k<8) {
                    if (reserved.contains({i, j+k})) {before.push_back({i, j+k});}
                    reserved.insert({i, j+k});
                }
                if (j+k<8 && i+k<8) {
                    if (reserved.contains({i+k, j+k})) {before.push_back({i+k, j+k});}
                    reserved.insert({i+k, j+k});
                }
                if (i-k>=0 && j+k<8) {
                    if (reserved.contains({i-k, j+k})) {before.push_back({i-k, j+k});}
                    else reserved.insert({i-k, j+k});
                }
                if (j-k>=0) {
                    if (reserved.contains({i, j-k})) {before.push_back({i, j-k});}
                    else reserved.insert({i, j-k});
                }
                if (i-k>=0 && j-k>=0) {
                    if (reserved.contains({i-k, j-k})) {before.push_back({i-k, j-k});}
                    else reserved.insert({i-k, j-k});
                }
                if (j-k>=0 && i+k<8) {
                    if (reserved.contains({i+k, j-k})) {before.push_back({i+k, j-k});}
                    else reserved.insert({i+k, j-k});
                }
                if (i+k<8) {
                    if (reserved.contains({i+k, j})) {before.push_back({i+k, j});}
                    else reserved.insert({i+k, j});
                }
                if (i-k>=0) {
                    if (reserved.contains({i-k, j})) {before.push_back({i-k, j});}
                    else reserved.insert({i-k, j});
                }
            }
            sols += solve(reserved, queens);
            queens.erase({i, j});
            reserved.erase({i, j});
            for (int k = 1; k < 8; k++) {
                if (j+k<8) reserved.erase({i, j+k});
                if (j+k<8 && i+k<8) reserved.erase({i+k, j+k});
                if (i-k>=0 && j+k<8)reserved.erase({i-k, j+k});
                if (j-k>=0) reserved.erase({i, j-k});
                if (i-k>=0 && j-k>=0) reserved.erase({i-k, j-k});
                if (j-k>=0 && i+k<8) reserved.erase({i+k, j-k});
                if (i+k<8) reserved.erase({i+k, j});
                if (i-k>=0) reserved.erase({i-k, j});
            }
            for (pair<int,int>k : before) {
                reserved.insert(k);
            }
        }
    }
    return sols;
}

int main() {
    set<pair<int, int>> reserved;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char temp;
            cin >> temp;
            if (temp == '*') {
                reserved.insert(pair<int, int>(i, j));
            }
        }
    }
    set<pair<int,int>> queens;
    cout << solve(reserved, queens) << '\n';
    return 0;
}