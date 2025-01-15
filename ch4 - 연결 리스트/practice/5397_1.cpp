#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        list<char> lst(1, ' ');
        // lst.push_front(' ');
        list<char>::iterator cursor = lst.begin();
        list<char>::iterator idx0 = lst.begin();


        string ln;
        cin >> ln;

        for (char c : ln) {
            switch (c) {
                case '<':
                    if (cursor != idx0) cursor--;
                    break;
                case '>':
                    if (cursor != --lst.end()) cursor++;
                    break;
                case '-':
                    if (cursor != idx0) {
                        cursor = lst.erase(cursor);
                        cursor--;
                    }
                    break;
                default:
                    cursor = lst.insert(++cursor, c);
                    break;
            }
        }

        for (list<char>::iterator iter = ++lst.begin(); iter != lst.end(); iter++)
            cout << *iter;
        cout << '\n';
    }
}