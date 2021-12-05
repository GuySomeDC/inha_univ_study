#include <iostream>
#include <queue>
#include <vector>
#define MAX_ROOM 10000
using namespace std;

int getReverse(int n) {
    int num[4] = {0};
    num[3] = (n / 1000) % 10;
    num[2] = (n / 100) % 10;
    num[1] = (n / 10) % 10;
    num[0] = n % 10;
    return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, A, B;
    
    vector<vector<int>> g(MAX_ROOM);
    for (int i = 0; i < MAX_ROOM; i++) {
        g[i].push_back(i + 1);
        if (i - 1 >= 0)
            g[i].push_back(i - 1);
        g[i].push_back(getReverse(i));
    }
    
    cin >> T;
    
    while (T--) {
        cin >> A >> B;
        vector<bool> visit(MAX_ROOM, false);
        
        queue<pair<int, int>> q;
        q.push({A, 0});
        visit[A] = true;
        
        while (!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            if (cur.first == B) {
                cout << cur.second << '\n';
                break;
            }
            for (size_t i = 0; i < g[cur.first].size(); i++) {
                if (!visit[g[cur.first][i]]) {
                    q.push({g[cur.first][i], cur.second + 1});
                    visit[g[cur.first][i]] = true;
                }
            }
        }
    }
    
    return 0;
}
