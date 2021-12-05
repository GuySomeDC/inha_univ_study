#include <iostream>
#include <vector>
#include <set>
#include <queue>
#define TICK_SIZE 8
#define RANGE_CHECK x > 0 && x <= n && y > 0 && y <= n
using namespace std;

vector<vector<int>> grid;
vector<vector<vector<pair<int, int>>>> white_connected_locations;
vector<vector<vector<pair<int, int>>>> black_connected_locations;
set<pair<int, int>> white_positions;
set<pair<int, int>> black_positions;
int T, n, Q, r, c, turn;

int x_tick[TICK_SIZE] = {-1, -1, -1, 0, 0, 1, 1, 1}, y_tick[TICK_SIZE] = {-1, 0, 1, -1, 1, -1, 0, 1};

set<pair<int, int>> getPossibleLocationSet(int turn) {
    set<pair<int, int>> result;
    set<pair<int, int>>& my_positions = (turn == 1 ? white_positions : black_positions);
    vector<vector<vector<pair<int, int>>>>& my_locations = (turn == 1 ? white_connected_locations : black_connected_locations);
    int x, y;
    for (auto iter = my_positions.begin(); iter != my_positions.end(); iter++) {
        for (int i = 0; i < TICK_SIZE; i++) {
            x = iter->first;
            y = iter->second;
            while ((x += x_tick[i]) && (y += y_tick[i]) && RANGE_CHECK) {
                if (grid[x][y] == turn || !grid[x][y])
                    break;
            }
            if (RANGE_CHECK && grid[x - x_tick[i]][y - y_tick[i]] != turn && !grid[x][y]) {
                result.insert({x, y});
                my_locations[x][y].push_back({iter->first, iter->second});
            }
        }
    }
    
    return result;
}

void putStone(pair<int, int> location, int turn) {
    vector<pair<int, int>>& locations = (turn == 1 ? white_connected_locations[location.first][location.second] : black_connected_locations[location.first][location.second]);
    set<pair<int, int>>& my_positions = (turn == 1 ? white_positions : black_positions);
    set<pair<int, int>>& enemy_positions = (turn == 2 ? white_positions : black_positions);
    for (size_t i = 0; i < locations.size(); i++) {
        int x_tick = locations[i].first - location.first, y_tick = locations[i].second - location.second;
        if (x_tick > 0) x_tick = 1; if (x_tick < 0) x_tick = -1; if (y_tick > 0) y_tick = 1; if (y_tick < 0) y_tick = -1;
        int x = location.first, y = location.second;
        while (make_pair(x, y) != locations[i]) {
            grid[x][y] = turn;
            enemy_positions.erase({x, y});
            my_positions.insert({x, y});
            x += x_tick;
            y += y_tick;
        }
    }
}

void clearVector() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            white_connected_locations[i][j].clear();
            black_connected_locations[i][j].clear();
        }
    }
}

void initData() {
    grid = vector<vector<int>>(n + 1, vector<int>(n + 1));
    white_connected_locations = vector<vector<vector<pair<int, int>>>>(n + 1, vector<vector<pair<int, int>>>(n + 1));
    black_connected_locations = vector<vector<vector<pair<int, int>>>>(n + 1, vector<vector<pair<int, int>>>(n + 1));
    white_positions.clear();
    black_positions.clear();
    black_positions.insert({n/2, n/2});
    black_positions.insert({n/2 + 1, n/2 + 1});
    white_positions.insert({n/2, n/2 + 1});
    white_positions.insert({n/2 + 1, n/2});
    grid[n/2][n/2] = 2;
    grid[n/2 + 1][n/2 + 1] = 2;
    grid[n/2][n/2 + 1] = 1;
    grid[n/2 + 1][n/2] = 1;
    turn = 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    while (T--) {
        cin >> n >> Q;
        initData();
        queue<pair<int, int>> input_q;
        while (Q--) {
            cin >> r >> c;
            input_q.push({r, c});
        }
        while (!input_q.empty()) {
            set<pair<int, int>> black_possible = getPossibleLocationSet(2);
            set<pair<int, int>> white_possible = getPossibleLocationSet(1);
            
            if (black_possible.empty() && white_possible.empty()) break;
            if (black_positions.empty() || white_positions.empty()) break;
            
            if (turn == 2 && black_possible.empty()) turn = 1;
            else if (turn == 1 && white_possible.empty()) turn = 2;
            
            r = input_q.front().first;
            c = input_q.front().second;
            input_q.pop();
            
            if (turn == 2 && black_possible.find(make_pair(r, c)) == black_possible.end()) {
                clearVector();
                continue;
            }
            else if (turn == 1 && white_possible.find(make_pair(r, c)) == white_possible.end()) {
                clearVector();
                continue;
            }
            
            putStone(make_pair(r, c), turn);
            clearVector();
            if (turn == 2) turn = 1;
            else if (turn == 1) turn = 2;
        }
        size_t white = white_positions.size(), black = black_positions.size();
        if (white > black) cout << 1 << '\n';
        else if (white < black) cout << 2 << '\n';
        else cout << 0 << '\n';
    }
    
    return 0;
}
