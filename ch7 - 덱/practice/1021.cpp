#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    deque<int> dq;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        dq.push_back(i + 1);
    /*
        앞 -> 뒤
        뒤 -> 앞
        앞 꺼내기

    */
    int num, count = 0;
    for (int i = 0; i < M; i++) {
        cin >> num;
        int pos, size = dq.size();
        

        for (int i = 0; i < size; i++) {
            if (dq[i] == num) {
                pos = i;
                break;
            }
        }
        
        if (pos < size - pos) {
            for (int i = 0; i < pos; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            count += pos;
        }
        else {
            for (int i = 0; i < size - pos; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            count += (size - pos);
        }
        dq.pop_front();
    }
    cout << count << '\n';

    return 0;
}

/*
1 2 3 4 5 6 7 8 9 10

2 3 4 5 6 7 8 9 10 1

3 4 5 6 7 8 9 10 1



*/