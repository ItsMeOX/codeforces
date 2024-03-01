#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Precompute the index the nearest left different element first.
// Then for each query, if prev[right] < left, then return -1 -1,
// other return prev[right]+1 and right+1.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int t, t2;
        cin >> t;
        vector<int> nums;
        while (t--) cin >> t2, nums.push_back(t2);

        vector<int> prev(nums.size(), -1);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]) prev[i] = i-1;
            else prev[i] = prev[i-1];
        }

        cin >> t;
        while (t--) {
            int left, right;
            int res_left = -1, res_right = -1;
            cin >> left >> right;
            left--, right--;

            if (prev[right] < left) cout << "-1 -1\n";
            else cout << prev[right]+1 << ' ' << right+1 << '\n';
        }
        cout << '\n';
    }

    return 0;
}