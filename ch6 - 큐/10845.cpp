#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    queue<int> q;
    int N;
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int t;
            cin >> t;
            q.push(t);
        }
        else if (command == "pop") {
            if (!q.empty()) {
                cout << q.front() << '\n';
                q.pop();
            }
            else cout << -1 << '\n';
        }
        else if (command == "size") {
            cout << q.size() << '\n';
        }
        else if (command == "empty") {
            cout << q.empty() << '\n';
        }
        else if (command == "front") {
            if (!q.empty()) cout << q.front() << '\n';
            else cout << -1 << '\n';
        }  
        else if (command == "back") {
            if (!q.empty()) cout << q.back() << '\n';
            else cout << -1 << '\n';
        }
    }
    return 0;
}