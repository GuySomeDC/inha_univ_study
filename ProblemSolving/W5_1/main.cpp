#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, period_size;
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        vector<int> v(N);
        
        for (int i = 0; i < N; i++) cin >> v[i];
        
        for (period_size = 1; period_size <= N; period_size++) if (vector<int>(v.begin(), v.end() - period_size) == vector<int>(v.begin() + period_size, v.end())) break;
        
        
        for (int i = 0; i < period_size; i++) cout << v[i] << ' ';
        cout << '\n';
    }
    
    return 0;
}
