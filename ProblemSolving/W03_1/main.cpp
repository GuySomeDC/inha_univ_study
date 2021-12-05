#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> dir;
vector<vector<int>> g;
vector<int> dir_length;

void dfs(int start, int depth) {
    if (dir_length[start]) return;
    dir_length[start] = depth + dir[start].length();
    
    for (int i = 0; i < (int)g[start].size(); i++) {
        dfs(g[start][i], dir_length[start] + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, A, B;
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        dir = vector<string>(N + 1);
        dir_length = vector<int>(N + 1);
        g = vector<vector<int>>(N + 1);
        for (int i = 1; i < N; i++) {
            cin >> A >> B;
            g[A].push_back(B);
        }
        for (int i = 1; i <= N; i++)
            cin >> dir[i];
        dfs(1, 0);
        for (int i = 1; i <= N; i++)
            cout << dir_length[i] << '\n';
    }
    
    return 0;
}
