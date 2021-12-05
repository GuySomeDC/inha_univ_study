#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> g;
vector<bool> visit;
int total = 0;
int last_node = 0;

void dfs(int start, int depth) {
    if (visit[start]) return;
    visit[start] = true;
    
    if (depth > total) {
        total = depth;
        last_node = start;
    }
    
    for (int i = 0; i < (int)g[start].size(); i++) {
        dfs(g[start][i].first, g[start][i].second + depth);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, n, u, v, d;
    cin >> T;
    while (T--) {
        cin >> n;
        g = vector<vector<pair<int, int>>>(n + 1);
        visit = vector<bool>(n + 1, false);
        
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v >> d;
            g[u].push_back({ v, d });
            g[v].push_back({ u, d });
        }
        total = 0;
        last_node = 0;
        dfs(1, 0);
        total = 0;
        visit = vector<bool>(n + 1, false);
        dfs(last_node, 0);
        cout << total << '\n';
    }
    
    return 0;
}
