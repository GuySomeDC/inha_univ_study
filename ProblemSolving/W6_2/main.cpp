#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int T, N, result = 0;
vector<vector<bool>> matrix;
pair<int, int> inha;
pair<int, int> safety;
pair<int, int> warrior;
pair<int, int> rifle;

void init() {
    result = 0;
    for (int i = 0; i <= N; i++) {
        matrix[i][0] = false;
        matrix[0][i] = false;
    }
    
    int x, y;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && x <= N && y <= N) matrix[x++][y++] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && x <= N && y > 0) matrix[x++][y--] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && x > 0 && y > 0) matrix[x--][y--] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && x > 0 && y <= N) matrix[x--][y++] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && x <= N) matrix[x++][y] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && x > 0) matrix[x--][y] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && y > 0) matrix[x][y--] = false;
    
    x = rifle.first;
    y = rifle.second;
    while (make_pair(x, y) != warrior && y <= N) matrix[x][y++] = false;
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            x = warrior.first + i;
            y = warrior.second + j;
            if (x >= 1 && x <= N && y >= 1 && y <= N) matrix[x][y] = false;
        }
    }
}

void bfs(pair<int, int> start, int depth) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        matrix = vector<vector<bool>>(N + 1, vector<bool>(N + 1, true));
        cin >> inha.first >> inha.second >> safety.first >> safety.second >> warrior.first >> warrior.second >> rifle.first >> rifle.second;
        init();
        queue<tuple<int, int, int>>q;
        q.push(make_tuple(inha.first, inha.second, 0));
        matrix[inha.first][inha.second] = false;
        
        while (!q.empty()) {
            tuple<int, int, int> cur = q.front();
            q.pop();
            
            if (make_pair(get<0>(cur), get<1>(cur)) == safety) {
                result = get<2>(cur);
                break;
            }
            
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int x = get<0>(cur) + i, y = get<1>(cur) + j;
                    if (x >= 1 && x <= N && y >= 1 && y <= N && matrix[x][y]) {
                        matrix[x][y] = false;
                        q.push(make_tuple(x, y, get<2>(cur) + 1));
                    }
                }
            }
        }
        
        cout << result << '\n';
    }
    
    return 0;
}
