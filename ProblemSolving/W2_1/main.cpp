#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, M, K;
    string s;
    
    cin >> T;
    
    while (T--) {
        cin >> N >> M;
        vector<queue<string>> v(N);
        queue<string> q;
        while (M--) {
            cin >> s;
            q.push(s);
        }
        bool correct = true;
        for (int i = 0; i < N; i++) {
            cin >> K;
            while (K--) {
                cin >> s;
                v[i].push(s);
            }
        }
        while (!q.empty())
        {
            bool temp = false;
            for (auto it = v.begin(); it != v.end(); it++) {
                if (it->front() == q.front()) {
                    temp = true;
                    q.pop();
                    it->pop();
                    break;
                }
            }
            if (!temp) {
                correct = false;
                break;
            }
        }
        cout << correct << '\n';
    }
    
    return 0;
}
