#include <iostream>
using namespace std;

int func4(int N) {
    int max_2;

    for (max_2 = 1; max_2 <= N; max_2 *= 2);

    return max_2 / 2;
}

int main() {
    cout << func4(97615282) << endl;
    // log(N)
    return 0;
}