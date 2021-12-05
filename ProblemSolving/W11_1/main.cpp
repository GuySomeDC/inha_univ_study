#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define ALPHABET_SIZE 26
using namespace std;

int N[ALPHABET_SIZE] = {0}, M, result = 0;
vector<pair<int, string>> words;

bool isPossible(int K) {
    vector<int> ind;
    for (int i = 0; i < M - K; i++) ind.push_back(0);
    for (int i = 0; i < K; i++) ind.push_back(1);
    do {
        int score = 0;
        int usage[ALPHABET_SIZE] = {0};
        bool flag = true;
        for (int i = 0; i < M && flag; i++) {
            if (ind[i]) {
                for (char w : words[i].second) {
                    if (++usage[w-97] > N[w-97]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) score += words[i].first;
            }
        }
        if (flag) {
            result = max(score, result);
            return true;
        }
    } while(next_permutation(ind.begin(), ind.end()));
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    for (int i = 0; i < ALPHABET_SIZE; i++) cin >> N[i];
    
    cin >> M;
    words = vector<pair<int, string>>(M);
    for (int i = 0; i < M; i++) cin >> words[i].second >> words[i].first;
    
    sort(words.begin(), words.end());
    
    int l = 1, r = M, mid;
    
    while (l <= r) {
        mid = (l + r) / 2;
        if (isPossible(mid)) l = mid + 1;
        else r = mid - 1;
    }
    cout << result;
    
    return 0;
}
