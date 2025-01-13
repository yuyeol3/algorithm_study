#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        list<char> lst;
        lst.push_front(' '); // 0th index;
        list<char>::const_iterator idx0 = lst.begin();
        list<char>::iterator cursor = lst.end();

        string commands;
        cin >> commands;
        for (char command : commands)
        {
            if (command == '<') {
                if (cursor != idx0) 
                    cursor--;
            }    
            else if (command == '>') {
                if (cursor != ++lst.end()) 
                    cursor++;
            }
            else if (command == '-') {
                if (cursor != idx0) {
                    if (cursor == lst.end())
                        cursor--;

                    if (cursor != idx0 && cursor != lst.end()) {
                        cursor = lst.erase(cursor);
                        cursor--;
                    }
                }
            }
            else {
                if (cursor == idx0) {
                    cursor = lst.insert(++cursor, command);
                    cursor++;
                }
                else {
                    cursor = lst.insert(cursor, command);
                    cursor++;
                }
            }
        }

        for (list<char>::iterator iter = ++lst.begin(); iter != lst.end(); iter++)
            cout << *iter;
        cout << '\n';
    }

    return 0;
}
/*


 */