#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> cacti(n, 0);
        vector<int> bird(n, 0);
        for (int i = 0; i < n; i++) {
            char temp;
            cin >> temp;
            if (temp == 'o') {continue;}
            if (temp == 'K') {cacti[i] = 1;}
            else if (temp == 'P') {bird[i] = 1;}
        }
        vector<int> prefix_sum(n);
        prefix_sum[0] = bird[0];
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + bird[i];
        }
        vector<int> dp(n, -1);
        dp[0] = 0;

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dp[i]!=-1) {
                if (i+1==n) {ans.push_back(dp[i]); continue;}
                if (cacti[i+1]==0) {if (dp[i+1]!=-1) {dp[i+1] = min(dp[i+1],dp[i]);} else {dp[i+1] = dp[i];}}
                if (i+k+1>=n && prefix_sum[min(n-1,i+k)]-prefix_sum[i+1]==0) {ans.push_back(dp[i]+1); continue;}
                if (cacti[i+k+1]==0 && prefix_sum[min(n-1,i+k)]-prefix_sum[i]==0) {if (dp[i+k+1]!=-1) {dp[i+k+1] = min(dp[i+k+1],dp[i]+1);} else {dp[i+k+1] = dp[i]+1;}}
            }
        }
        int out = INT_MAX;
        for (int i : ans) {
            out = min(out, i);
        }
        if (out == INT_MAX) {out = -1;}
        cout << out << "\n";
    }
}