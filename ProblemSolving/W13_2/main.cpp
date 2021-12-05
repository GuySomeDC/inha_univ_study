#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, N, M;
    
    cin >> T;
    
    while (T--) {
        cin >> N >> M;
        vector<int> sender(M);
        unordered_set<int> reader;
        vector<size_t> answer(M);
        for (int i = 0; i < M; i++) cin >> sender[i];
        for (int i = M-1; i >= 0; i--) {
            reader.insert(sender[i]);
            answer[i] = reader.size();
        }
        for (int i = 0; i < M; i++) cout << N - answer[i] << '\n';
    }
    
    return 0;
}
