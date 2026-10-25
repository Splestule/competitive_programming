#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while(t--) {
        int N, M;
        ll MAX_ALLOWED;
        cin >> N >> MAX_ALLOWED >> M;

        vector<ll> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];
        ll lowest;
        if (M != 0) {
            lowest = *min_element(a.begin(), a.end());
        }
        vector<pair<ll, int>> order(N);
        for (int i = 0; i < N; i++) order[i] = {a[i], i};
        sort(order.begin(), order.end());
        vector<int> magnitude(N+2, 0);
        int threshold{};
        int longest{};
        auto longest_window = [&](ll c) -> int {
            for (int i = threshold; i < N; i++) {
                int pos = order[i].second;
                if (order[i].first <= c) {
                    threshold = i+1;
                    magnitude[pos+1] = 1 + magnitude[pos] + magnitude[pos+2];
                    int l = pos+1 - magnitude[pos];
                    int r = pos+1 + magnitude[pos+2];
                    magnitude[r] = magnitude[pos+1];
                    magnitude[l] = magnitude[pos+1];
                    longest = max(longest, magnitude[pos+1]);
                }
                else break;
            }
            return longest;
        };
        auto solve = [&]() -> int {
            int l{}; int r{};
            int longest_path{};
            ll mx = a[0]; ll mn = a[0]; multiset<ll> w = {a[0]};
                while (r<N) {
                    if (mx - mn <= MAX_ALLOWED) {
                        if (r-l>longest_path) longest_path = r-l;
                        r++;
                        if (r==N) break;
                        w.insert(a[r]);
                        if (a[r] > mx) mx = a[r];
                        else if (a[r] < mn) mn = a[r];
                    }
                    else {
                        w.erase(w.find(a[l]));
                        if (a[l] == mx) {mx = *w.rbegin();}
                        else if (a[l] == mn) {mn = *w.begin();}
                        l++;
                    }
                }
            return longest_path;
        };
        int no_snow = solve() + 1;
        cout << no_snow << ' ';
        for (int i = 0; i < M; i++) {
            cout << max(no_snow, longest_window(lowest + i+1 + MAX_ALLOWED)) << ' ';
        }
        cout << '\n';
    }
    return 0;
}