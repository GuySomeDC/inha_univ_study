#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, x, y, result;
    
    cin >> T;
    
    while (T--) {
        priority_queue<tuple<int, int, int>> pq;
        cin >> N;
        bool t = true;
        result = 0;
        while (N--) {
            cin >> x >> y;
            pq.push(make_tuple(x + y, x, y));
        }
        while (!pq.empty()) {
            if (t) {
                result += get<1>(pq.top());
            }
            else {
                result -= get<2>(pq.top());
            }
            pq.pop();
            t = !t;
        }
        cout << result << '\n';
    }
    
    return 0;
}
