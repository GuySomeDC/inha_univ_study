#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N;
    
    cin >> T;
    
    while (T--) {
        int result = 0;
        cin >> N;
        vector<int> matryoshka(N);
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            int k = 0;
            cin >> matryoshka[i];
            for (int j = 0; j < i; j++)
                if (matryoshka[i] > matryoshka[j])
                    if (arr[j] > k) k = arr[j];
            arr[i] = k + 1;
            if (arr[i] > result) result = arr[i];
        }
        cout << result << '\n';
    }
    
    return 0;
}
