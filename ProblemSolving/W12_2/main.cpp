#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, cnt = 0, min_dist = 2147483647;
    
    cin >> T;
    
    while (T--) {
        cnt = 0;
        min_dist = 2147483647;
        cin >> N;
        vector<pair<int, int>> room(N);
        for (int i = 0; i < N; i++) cin >> room[i].first >> room[i].second;
        sort(room.begin(), room.end());
        for (int i = N - 1; i >= 0; i--) {
            if (room[i].second > min_dist) cnt++;
            min_dist = min(min_dist, room[i].second);
        }
        cout << N - cnt << '\n';
    }
    
    return 0;
}
