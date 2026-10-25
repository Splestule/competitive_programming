#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    int N, P;
    cin >> N >> P;

    if (P == 0) {cout << "YES\n";return 0;}
    if (N == 1) {cout << "NO\n"; return 0;}

    vector<pair<int,int>> points;
    for (int i = 0; i < N; i++) {
        pair<int,int> p;
        cin >> p.first >> p.second;
        points.push_back(p);
    }

    map<tuple<int,int,int>, int> lines;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int a, b;
            a = points[j].second - points[i].second; b = points[i].first - points[j].first;
            float x_mid = static_cast<float>(points[i].first+points[j].first)/static_cast<float>(2);
            float y_mid = static_cast<float>(points[i].second+points[j].second)/static_cast<float>(2);
            int a_n = b, b_n = -1*a, c_n = a_n*x_mid+b_n*y_mid;
            int divider = gcd(gcd(a_n,b_n),c_n);
            a_n/=divider; b_n/=divider; c_n/=divider;

            if (lines.count({a_n,b_n,c_n})) {lines[{a_n,b_n,c_n}]++;}
            else {lines.insert(make_pair(make_tuple(a_n,b_n,c_n), 1));}
        }
    }
    int mx{};
    for (auto& p : lines) {
        mx = max(mx,p.second);
    }
    if (static_cast<float>(mx*2)/static_cast<float>(N) < static_cast<float>(P)/static_cast<float>(100)) {cout << "NO\n"; return 0;}
    else {cout << "YES\n"; return 0;}
}