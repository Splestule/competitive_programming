#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll factorial(int n) {
    ll result = 1;
    for (int i = 1; i <= n; i++) result *= i;
    return result;
}

ll repeated_perms(array<int, 128> perm) {
    int sum{};
    ll denominator = 1;
    for (int i : perm) {
        sum += i;
        denominator *= factorial(i);
    }

    return (factorial(sum))/(denominator);
}

void option_tree(string& s, const vector<char>& letters, vector<int>& letter_counts, const int pos) {
    if (pos == s.size()) {
        cout << s << '\n';
        return;
    }
    for (int i = 0; i < size(letters); i++) {
        if (letter_counts[i] > 0) {
            s[pos] = letters[i];
            letter_counts[i]--;
            option_tree(s, letters, letter_counts, pos + 1);
            letter_counts[i]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int size = s.size();

    string out(size, '-');
    string& permutation_string = out;
    array<int, 128> cnt{};
    for (const unsigned char c : s) cnt[c]++;

    vector<char> letters;
    vector<int> letters_counts;
    for (int i = 0; i < 128; i++) {
        if (cnt[i] != 0) letters_counts.push_back(cnt[i]), letters.push_back(static_cast<char>(i));
    }

    cout << repeated_perms(cnt) << '\n';

    option_tree(permutation_string, letters, letters_counts, 0);

    return 0;
}