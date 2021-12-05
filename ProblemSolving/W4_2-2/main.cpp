#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    vector<pair<double, double>> v(5);
    cin >> T;
    
    while (T--) {
        int result = 1;
        cin >> v[1].first >> v[1].second >> v[2].first >> v[2].second;
        cin >> v[3].first >> v[3].second >> v[4].first >> v[4].second;
        pair<double, double> L1_min = min(v[1], v[2]);
        pair<double, double> L1_max = max(v[1], v[2]);
        pair<double, double> L2_min = min(v[3], v[4]);
        pair<double, double> L2_max = max(v[3], v[4]);
        double d = (v[1].first - v[2].first) * (v[3].second - v[4].second) - (v[1].second - v[2].second) * (v[3].first - v[4].first);
        if (d == 0) {
            if (
                (v[1].first - v[2].first) * (v[3].first - v[4].first) * v[1].second - (v[3].first - v[4].first) * (v[1].second - v[2].second) * v[1].first
                == (v[1].first - v[2].first) * (v[3].first - v[4].first) * v[3].second - (v[1].first - v[2].first) * (v[3].second - v[4].second) * v[3].first
                &&
                (v[1].second - v[2].second) * (v[3].second - v[4].second) * v[1].first - (v[3].second - v[4].second) * (v[1].first - v[2].first) * v[1].second
                == (v[1].second - v[2].second) * (v[3].second - v[4].second) * v[3].first - (v[1].second - v[2].second) * (v[3].first - v[4].first) * v[3].second
                ) {
                    if ((L1_min <= L2_min && L2_max <= L1_max) || (L2_min <= L1_min && L1_max <= L2_max)) {
                        result = 4;
                    }
                    else if (L1_max == L2_min || L1_min == L2_max) {
                        result = 2;
                    }
                    else if (L1_min > L2_max || L2_min > L1_max) {
                        result = 1;
                    }
                    else {
                        result = 3;
                    }
                }
        }
        else {
            double x = ((v[1].first - v[2].first) * (v[3].second - v[4].second) * v[3].first
                        - (v[1].first - v[2].first) * (v[3].first - v[4].first) * v[3].second
                        - (v[1].second - v[2].second) * (v[3].first - v[4].first) * v[1].first
                        + (v[1].first - v[2].first) * (v[3].first - v[4].first) * v[1].second) / d;
            double y = ((v[1].first - v[2].first) * (v[3].second - v[4].second) * v[1].second
                        - (v[1].second - v[2].second) * (v[3].second - v[4].second) * v[1].first
                        - (v[1].second - v[2].second) * (v[3].first - v[4].first) * v[3].second
                        + (v[1].second - v[2].second) * (v[3].second - v[4].second) * v[3].first) / d;
            if (min(v[1].first, v[2].first) <= x && x <= max(v[1].first, v[2].first)
                && min(v[3].first, v[4].first) <= x && x <= max(v[3].first, v[4].first)
                && min(v[1].second, v[2].second) <= y && y <= max(v[1].second, v[2].second)
                && min(v[3].second, v[4].second) <= y && y <= max(v[3].second, v[4].second)) {
                result = 2;
            }
        }
        cout << result << '\n';
    }
    
    return 0;
}
