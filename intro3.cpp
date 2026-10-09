#include <bits/stdc++.h>
using namespace std;

int main() {
    string genes;
    int window = 1;
    int max_window = 1;
    cin >> genes;
    for (int i = 0; i < genes.length(); i++) {
        if (i > 0) {
            if (genes[i] == genes[i - 1]) {
                window++;
            }
            else {
                window = 1;
            }
            if (window > max_window) {
                max_window = window;
            }
        }
    }
    cout << max_window << "\n";
    return 0;
}