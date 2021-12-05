#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, K;
    string S;
    
    cin >> T;
    
    while (T--) {
        cin >> S >> K;
        
        for (int i = 0; i < K; i++) {
            for (int j = 0;; j++) {
                int idx = j * K + (j % 2 ? K - i - 1 : i);
                if (idx >= (int)S.length())
                    break;
                cout << S[idx];
            }
        }
        cout << '\n';
    }
    
    return 0;
}
