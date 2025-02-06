#include <bits/stdc++.h>
using namespace std;

int z(int n, int r, int c) {
    if (n == 0) return 0;
    int n2 = 1 << n;
    int half = n2 / 2;
    int pr = (int) r >= half;
    int pc = (int) c >= half;
    int coeffs[2][2] = {{0, 1}, {2, 3}};
    int coeff = coeffs[pr][pc];

    return (half*half*coeff) + z(n-1, r - pr * half, c - pc * half);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int N, R, C;
    cin >> N >> R >> C;
    cout << z(N, R, C);
}