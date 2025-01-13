#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    stack<int> s;

    string command;
    for (int i = 0; i < N; i++) {
        cin >> command;

        if (command == "push") {
            int num;
            cin >> num;
            s.push(num);
        }
        else if (command == "pop") {
            if (s.empty()) cout << -1 << '\n';
            else {
                cout << s.top() << '\n';
                s.pop();
            } 
        }
        else if (command == "size") {
            cout << s.size() << '\n';
        }
        else if (command == "empty") {
            if (s.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (command == "top") {
            if (s.empty()) cout << -1 << '\n';
            else cout << s.top() << '\n';
        }
    }

    return 0;
}