#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll toint() {
    ll res = 1;
    int M;
    cin >> M;
    vector<int> star_pos(M);
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < static_cast<int>(s.length()); j++) {
            if (s[j] == '#') {star_pos[i]=j;}
        }
    }
    for (int i = 1; i < M; i++) {
        if (star_pos[i-1] > star_pos[i]) {res*=2;res++;}
        else {res*=2;}
    }
    return res;
}

void tonum(ll num) {
    vector<int> instructions{}; instructions.push_back(0);
    int curr{}; int mn{}; int mx{};
    while (num != 1) {
        if (num % 2 == 0) {
            curr--;
            instructions.push_back(curr);
        }
        else {curr++; instructions.push_back(curr);}
        num /= 2;
        mx = max(mx, curr); mn = min(mn, curr);
    }
    cout << instructions.size() << '\n';
    for (int i = instructions.size(); i > 0; i--) {
        for (int j = 0; j < instructions[i-1] - mn; j++) {
            cout << '.';
        }
        cout << '#';
        for (int j = 0; j < mx - instructions[i-1]; j++) {
            cout << '.';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A = toint();
    ll B = toint();

    tonum(A+B);
    return 0;
}