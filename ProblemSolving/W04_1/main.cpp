#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, A, B, x, y, gcd, R;
    
    cin >> T;
    
    while (T--) {
        cin >> A >> B >> x >> y;
        gcd = abs(A - B);
        R = A % gcd;
        cout << gcd << ' ' << min((gcd - R) * x, (A - R > 1 && B - R > 1) ? y * R : 2147483647) << '\n';
    }
    
    return 0;
}
