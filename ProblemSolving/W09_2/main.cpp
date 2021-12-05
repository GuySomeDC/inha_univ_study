#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<vector<int>> grid;
vector<vector<vector<pair<int, int>>>> white_connected_locations;
vector<vector<vector<pair<int, int>>>> black_connected_locations;
int T, n, Q, r, c, white, black, turn;

set<pair<int, int>> getPossibleLocationSet(int turn) {
    set<pair<int, int>> result;
    int x, y;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (grid[i][j] == turn) {
                x = i;
                y = j;
                while (--x && x > 0) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (x > 0 && grid[x+1][y] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (++x && x <= n) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (x <= n && grid[x-1][y] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (--y && y > 0) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (y > 0 && grid[x][y+1] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (++y && y <= n) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (y <= n && grid[x][y-1] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (++y && --x && y <=n && x > 0) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (y <=n && x > 0 && grid[x+1][y-1] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (++y && ++x && y <=n && x <= n) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (y <=n && x <= n && grid[x-1][y-1] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (--y && --x && y > 0 && x > 0) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (y > 0 && x > 0 && grid[x+1][y+1] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
                x = i;
                y = j;
                while (--y && ++x && y > 0 && x <= n) {
                    if (grid[x][y] == turn || !grid[x][y])
                        break;
                }
                if (y > 0 && x <= n && grid[x-1][y+1] != turn && !grid[x][y]) {
                    result.insert({x, y});
                    if (turn == 1) white_connected_locations[x][y].push_back(make_pair(i, j));
                    else if (turn == 2) black_connected_locations[x][y].push_back(make_pair(i, j));
                }
            }
        }
    }
    
    return result;
}

void putStone(pair<int, int> location, int turn) {
    int enemy = (turn == 1 ? 2 : 1);
    if (turn == 1) {
        white++;
    } else if (turn == 2) {
        black++;
    }
    vector<pair<int, int>>& locations = (turn == 1 ? white_connected_locations[location.first][location.second] : black_connected_locations[location.first][location.second]);
    for (size_t i = 0; i < locations.size(); i++) {
        int x_tick = locations[i].first - location.first, y_tick = locations[i].second - location.second;
        if (x_tick > 0) x_tick = 1;
        if (x_tick < 0) x_tick = -1;
        if (y_tick > 0) y_tick = 1;
        if (y_tick < 0) y_tick = -1;
        int x = location.first, y = location.second;
        while (make_pair(x, y) != locations[i]) {
            if (grid[x][y] == enemy) {
                if (turn == 1) {
                    black--;
                    white++;
                } else if (turn == 2) {
                    white--;
                    black++;
                }
            }
            grid[x][y] = turn;
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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> T;
    
    while (T--) {
        cin >> n >> Q;
        grid = vector<vector<int>>(n + 1, vector<int>(n + 1));
        white_connected_locations = vector<vector<vector<pair<int, int>>>>(n + 1, vector<vector<pair<int, int>>>(n + 1));
        black_connected_locations = vector<vector<vector<pair<int, int>>>>(n + 1, vector<vector<pair<int, int>>>(n + 1));
        grid[n/2][n/2] = 2;
        grid[n/2 + 1][n/2 + 1] = 2;
        grid[n/2][n/2 + 1] = 1;
        grid[n/2 + 1][n/2] = 1;
        
        white = 2;
        black = 2;
        turn = 2;
        queue<pair<int, int>> input_q;
        while (Q--) {
            cin >> r >> c;
            input_q.push({r, c});
        }
        while (!input_q.empty()) {
            set<pair<int, int>> black_possible = getPossibleLocationSet(2);
            set<pair<int, int>> white_possible = getPossibleLocationSet(1);
            
            if (black_possible.empty() && white_possible.empty()) break;
            if (!white || !black) break;
            
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
        if (white > black) cout << 1 << '\n';
        else if (white < black) cout << 2 << '\n';
        else cout << 0 << '\n';
    }
    
    return 0;
}
