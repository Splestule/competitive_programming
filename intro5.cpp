#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    deque<int> v;
    deque<int> todo;
    for (int i = 0; i < n; i++) {
        if (i == 0) v.push_back(i+1);
        else if (abs(v[v.size() - 1] - i) > 1) v.push_back(i+1);
        else if (abs(v[0] - i) > 1) v.insert(v.begin(),i+1);
        else todo.push_back(i+1);

    }
    int no_moves = 0;
    int todo_size = todo.size();
    while (todo.size() > 0) {
        int t = todo[0];
        if (no_moves > todo_size) {
            cout << "NO SOLUTION";
            return 0;
        }
        if (abs(v[v.size() - 1] - t) > 1) v.push_back(t), todo.erase(todo.begin()), no_moves = 0;
        else if (abs(v[0] - t) > 1) v.insert(v.begin(),t), todo.erase(todo.begin()), no_moves = 0;
        else todo.erase(todo.begin()), todo.push_back(t), no_moves++;
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    return 0;
}