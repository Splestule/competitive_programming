#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main () {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int temp;
        vector<int> positions(N);
        for (int i = 0; i < N; i++) {
            cin >> temp;
            positions[temp-1] = i;
        }

        for (int i = 0; i < K; i++) {
            int A, B;
            cin >> A >> B; A--; B--;
            positions[A]--; positions[B]++;
        }
        vector<int> answer(N);
        for (int i = 0; i < N; i++) {
            answer[positions[i]] = i+1;
        }
        for (int i = 0; i < N; i++) {cout << answer[i] << " ";}
        cout << '\n';
    }
    return 0;
}