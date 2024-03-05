#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// We only need the largest three elements from each array,
// once we get the three largest elements, do a 3^3 brute force on every permutations of the three largest elements,
// and the answer will be the three largest elements with different days.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int t;
        cin >> t;
        vector<pair<int, int>> a(t, {0, 0}), b(t, {0, 0}), c(t, {0, 0});

        int tt;
        for (int i = 0; i < t; i++) {
            cin >> tt;
            a[i].first = tt;
            a[i].second = i;
        }
        for (int i = 0; i < t; i++) {
            cin >> tt;
            b[i].first = tt;
            b[i].second = i;
        }
        for (int i = 0; i < t; i++) {
            cin >> tt;
            c[i].first = tt;
            c[i].second = i;
        }

        sort(a.begin(), a.end(), greater<pair<int, int>>());
        sort(b.begin(), b.end(), greater<pair<int, int>>());
        sort(c.begin(), c.end(), greater<pair<int, int>>());

        // find the three largest elements from array a, b, and c on the different day
        int res = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (a[i].second == b[j].second) continue;
                for (int k = 0; k < 3; k++) {
                    if (c[k].second == a[i].second || c[k].second == b[j].second) continue;
                    res = max(res, a[i].first + b[j].first + c[k].first);
                }        
            }
        }

        cout << res << '\n';

    }

    return 0;
}