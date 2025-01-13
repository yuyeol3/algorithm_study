#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K;
    cin >> N >> K;

    list<int> lst;

    for (int i = 0; i < N; i++)
        lst.push_back(i+1);

    list<int>::iterator iter = --lst.end();
    cout << '<';
    while (true) {
        for (int i = 0; i < K; i++) {
            if (iter == --lst.end()) iter = lst.begin();
            else iter++;
        }

        cout << *iter;
        iter = lst.erase(iter);
        iter--;

        if (lst.empty())
            break;
        
        cout << ", ";
    }

    cout << '>' << '\n';
    return 0;
}