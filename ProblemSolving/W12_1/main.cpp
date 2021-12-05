#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N;
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        vector<vector<int>> triangle(N, vector<int>(N));
        vector<vector<int>> score(N, vector<int>(N));
        for (int i = 0; i < N; i++) for (int j = 0; j <= i; j++) cin >> triangle[i][j];
        for (int i = 0; i < N; i++) score[N-1][i] = triangle[N-1][i];
        for (int i = N-2; i >= 0; i--) for (int j = 0; j <= i; j++) score[i][j] = triangle[i][j] + min(score[i+1][j], score[i+1][j+1]);
        cout << score[0][0] << '\n';
    }
    
    return 0;
}
