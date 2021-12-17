#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int N, M;
ll high_bits, low_bits;
vector<pair<ll, ll>> sw;

bool isPossible(int K) {
    vector<int> ind;
    for (int i = 0; i < N - K; i++) ind.push_back(0);
    for (int i = 0; i < K; i++) ind.push_back(1);
    do {
        ll high = high_bits, low = low_bits;
        for (int i = 0; i < N; i++) {
            if (ind[i]) {
                high = high ^ sw[i].first;
                low = low ^ sw[i].second;
            }
        }
        if (high + low == 0) return true;
    } while (next_permutation(ind.begin(), ind.end()));
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T, K, x;
    cin >> T;
    while (T--) {
        high_bits = (ll)0;
        low_bits = (ll)0;
        cin >> N >> M;
        sw = vector<pair<ll, ll>>(N, { 0,0 });
        for (int i = 0; i < M; i++) {
            cin >> x;
            if (x) {
                if (i < 64) low_bits |= (ll)1 << i;
                else high_bits |= (ll)1 << (i - 64);
            }
        }
        for (auto& s : sw) {
            cin >> K;
            while (K--) {
                cin >> x;
                if (x < 65) s.second |= (ll)1 << (x - 1);
                else s.first |= (ll)1 << (x - 65);
            }
        }
        
        bool flag = false;
        for (int i = 1; i <= N; i++) {
            flag = isPossible(i);
            if (flag) break;
        }
        cout << flag << '\n';
    }
    
    return 0;
}
