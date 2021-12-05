#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> paper;
int red_paper, blue_paper, red_size, blue_size;

void cutPaper(int size, int x, int y) {
    bool complete = true;
    char prev = paper[x][y];
    for (int i = x; i < x + size && complete; i++) {
        for (int j = y; j < y + size && complete; j++) {
            if (prev != paper[i][j]) complete = false;
            prev = paper[i][j];
        }
    }
    if (complete) {
        if (prev == 'R') {
            red_paper++;
            red_size += size * size;
        } else {
            blue_paper++;
            blue_size += size * size;
        }
        return;
    }
    cutPaper(size / 2, x, y);
    cutPaper(size / 2, x + size/2, y);
    cutPaper(size / 2, x, y + size/2);
    cutPaper(size / 2, x + size/2, y + size/2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N;
    
    cin >> T;
    
    while (T--) {
        cin >> N;
        paper = vector<vector<char>>(N, vector<char>(N));
        red_paper = 0; red_size = 0; blue_paper = 0; blue_size = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                cin >> paper[i][j];
        cutPaper(N, 0, 0);
        cout << red_paper << ' ' << red_size << ' ' << blue_paper << ' ' << blue_size << '\n';
    }
    
    return 0;
}
