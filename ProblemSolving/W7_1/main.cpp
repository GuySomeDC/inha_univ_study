#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> g;
vector<int> c;
vector<bool> visit;
int cur;

void dfs(int start) {
    if (visit[start]) return;
    visit[start] = true;
    c[cur]++;
    
    for (size_t i = 0; i < g[start].size(); i++) {
        dfs(g[start][i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, M, N, A, B;
    
    cin >> T;
    
    while (T--) {
        cin >> N >> M;
        g = vector<vector<int>>(N+1);
        c = vector<int>(N+1, -1);
        while (M--) {
            cin >> A >> B;
            g[A].push_back(B);
        }
        
        for (cur = 1; cur <= N; cur++) {
            visit = vector<bool>(N+1, false);
            dfs(cur);
            cout << c[cur] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
