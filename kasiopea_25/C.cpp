#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int N, H;
        cin >> N >> H;

        map<ll, int> ys;
        vector<ll> xs(N);
        set<ll> s;
        map<ll, int> iter;
        for (int i = 0; i < N; i++) {
            ll x; int y;
            cin >> x >> y; x--; y--;
            xs[i] = x;
            ys[x] = y;
            s.insert(x);
        }
        sort(xs.begin(), xs.end());

        for (int i = 0; i < N; i++) {iter[xs[i]] = i;}

        int range = 2*H;
        auto ok = [&](pair<ll, int> a, pair<ll, int> b) {
            if (abs(b.first - a.first)%2==0) {
                if (abs(b.second - a.second)%2==0 || ((H-1-a.second)+(H-1-b.second))<=abs(a.first-b.first) || ((a.second)+(b.second))<=abs(a.first-b.first)) {}
                else return false;
            }
            if (abs(b.first - a.first)%2==1) {
                if (abs(b.second - a.second)%2==1 || ((H-1-a.second)+(H-1-b.second))<=abs(a.first-b.first) || ((a.second)+(b.second))<=abs(a.first-b.first)) {}
                else return false;
            }
            return abs(b.second-a.second) <= abs(b.first-a.first);
        };

        vector<int> dp(N, 0);
        int total{};

        for (int i = 0; i < N; i++) {
            bool look_back = true;
            if (ok({0,0}, make_pair(xs[i], ys[xs[i]]))) {dp[i] = 1;}
            for (ll j = max(xs[i]-range,0LL); j < xs[i]; j++) {

                if ((s.find(j) != s.end()) && ok(make_pair(j, ys[j]), make_pair(xs[i], ys[xs[i]])) && dp[iter[j]] != 0) {
                    dp[i] = max(dp[i], dp[iter[j]]+1);
                    if (look_back) {dp[i] = max(dp[i], dp[iter[j-1]]+1); look_back = false;}
                }
            }

            total = max(total, dp[i]);
        }
        cout << total << '\n';
    }
    return 0;
}