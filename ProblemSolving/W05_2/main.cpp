#include <iostream>
#include <vector>
using namespace std;

vector<int> h;
int N, M;

bool isCorrect(int dist) {
    int cnt = 1;
    int length = 0;
    
    for (int i = 1; i < N; i++) {
        length += h[i] - h[i - 1];
        if (length >= dist) {
            cnt++;
            length = 0;
        }
        if (cnt >= M)
            return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;
    
    h = vector<int>(N);
    
    for (int i = 0; i < N; i++)
        cin >> h[i];
    
    int left = 0, right = h[N - 1] / (M - 1), result = 0;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        bool correct = isCorrect(mid);
        if (correct) {
            left = mid + 1;
            result = mid;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << result;
    
    return 0;
}
