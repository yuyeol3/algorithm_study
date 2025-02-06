#include <bits/stdc++.h>
using namespace std;

void printN(int n) {
    if (n == 0) {
        cout << '\n';
        return;
    } 

    cout << n << ' ';
    printN(n-1);
}

int main() {
    printN(10);
    return 0;
}