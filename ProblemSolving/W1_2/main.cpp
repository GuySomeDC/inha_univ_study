#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, x, c;
    int min_v, max_v;
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        
        stack<pair<int, int>> s;
        
        while (N--) {
            cin >> c;
            
            if (c == 1) {
                cin >> x;
                if (s.empty()) {
                    s.push({ x, x });
                }
                else {
                    min_v = s.top().first;
                    max_v = s.top().second;
                    if (x > max_v) max_v = x;
                    if (x < min_v) min_v = x;
                    s.push({ min_v, max_v });
                }
                cout << s.top().first << ' ' << s.top().second << '\n';
            }
            else if(!s.empty()) {
                s.pop();
            }
        }
    }
    
    return 0;
}
