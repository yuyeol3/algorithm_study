#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// O(log b)
ll f(ll a, ll b, ll c) {
    if (b == 0) return 1LL;
    if (b == 1) return (ll) a % c;

    ll res = f(a, b/2, c) % c;
    
    if (b % 2 == 0) return (res * res) % c;
    else return (((res * res) % c) * a) % c;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    cout << f(a, b, c) << '\n';
}