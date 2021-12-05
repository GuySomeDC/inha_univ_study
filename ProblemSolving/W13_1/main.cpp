#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string grid[3000] = {};
    
    int N, M;
    cin >> N >> M;
    set<string> text_set;
    string big_string;
    string s;
    
    for (int i = 0; i < N; i++) cin >> grid[i];

    for (int i = 0; i < N; i++) {
        string s1 = ""; string s2 = "";
        for (int j = 0; j < N; j++) {
            s1 += grid[i][j]; s2 += grid[j][i];
        }
        text_set.insert(s1); text_set.insert(s2);
    }
    
    for (int i = 0; i < N; i++) {
        string s1 = ""; string s2 = "";
        int x = i-1, y = -1;
        while (++x < N && ++y < N) {
            s1 += grid[x][y]; s2 += grid[y][x];
        }
        text_set.insert(s1); text_set.insert(s2);
    }
    
    for (auto iter = text_set.begin(); iter != text_set.end(); iter++) big_string += *iter + "|";
    
    for (int i = 0; i < M; i++) {
        cin >> s;
        cout << (big_string.find(s) != string::npos) << '\n';
    }

    return 0;
}
