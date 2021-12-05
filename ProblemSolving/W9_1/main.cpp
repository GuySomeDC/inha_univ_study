#include <iostream>
using namespace std;
typedef long long ll;

ll T, X, N, M;

ll pow(ll x, ll n) {
    ll r = 1;
    
    while (n) {
        if (n % 2)
            r = r * x % M;
        x = x * x % M;
        n /= 2;
    }
    
    return r;
}

ll f(ll n) {
    if (n == 1) return X % M;
    if (n % 2 == 1) return ((1 + pow(X, n / 2)) * f(n / 2) + pow(X, n)) % M;
    return ((1 + pow(X, n / 2)) * f(n / 2)) % M;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    while (T--) {
        cin >> X >> N >> M;
        cout << f(N) << '\n';
    }
    
    return 0;
}
