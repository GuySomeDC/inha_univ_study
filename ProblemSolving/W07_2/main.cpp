#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, M, x, y;
    size_t K;
    
    cin >> T;
    
    while (T--) {
        cin >> M >> N >> K;
        priority_queue<tuple<int, int, int>> pq;
        for (int i = 0; i < M; i++) {
            cin >> x >> y;
            if (pq.size() < K)
                pq.push(make_tuple(x*x + y*y, x, y));
            else if (make_tuple(x*x + y*y, x, y) < pq.top()) {
                pq.push(make_tuple(x*x + y*y, x, y));
                pq.pop();
            }
        }
        
        for (int i = 0; i < N; i++) {
            cin >> x >> y;
            if (make_tuple(x*x + y*y, x, y) < pq.top()) {
                pq.push(make_tuple(x*x + y*y, x, y));
                pq.pop();
            }
            cout << get<1>(pq.top()) << ' ' << get<2>(pq.top()) << '\n';
        }
    }
    
    return 0;
}
