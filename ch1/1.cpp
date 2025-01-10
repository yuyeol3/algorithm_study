#include <iostream>
using namespace std;

int func1(int lim) {
    int sum = 0;
    for (int i = 1; i <= lim; i++) {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }

    return sum;
}

int main() {
    cout << func1(34567) << endl;
    return 0;
    // 시간복잡도 O(N)
}