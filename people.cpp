#include <bits/stdc++.h>
using namespace std;
using ll = long long;

    struct Person {
        string name;
        int score{};
    };

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Person> p(n);

+
    for (int i = 0; i < n; i++) {
        cin >> p[i].name >> p[i].score;
    }

    sort(p.begin(), p.end(), [](const Person &a, const Person &b) {return a.score > b.score;});

    set<int> s;

    int offset = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            if (p[i].score == p[i - 1].score) {
                offset++;
            }
        }
        s.insert(i - offset + 1);
        cout << p[i].name << " " << p[i].score << " " << i - offset + 1 << endl;
    }
    cout << s.size() << endl;

    return 0;
}