#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, t, p, mt = 0;
    
    cin >> N >> M;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    queue<pair<int, int>> q;
    vector<int> v(N);
    
    while (M--) {
        cin >> t >> p;
        q.push({ t, p });
    }
    
    for (int i = 0; i < N; i++) {
        pq.push({ 0, i });
    }
    
    while (!q.empty()) {
        pair<int, int> c = pq.top();
        pq.pop();
        c.first += q.front().first;
        v[c.second] += q.front().second;
        if (c.first > mt) mt = c.first;
        q.pop();
        pq.push(c);
    }
    
    cout << mt << '\n';
    
    for (int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }
    
    return 0;
}
