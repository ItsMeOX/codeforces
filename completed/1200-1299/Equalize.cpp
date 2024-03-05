#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Find the subarray where max(subarray) - min(subarray) <= n-1.
// The answer is the longest length of subarray.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, ori_size, t;
        cin >> n;
        ori_size = n;
        unordered_set<int> nums_set;
        while (n--) cin >> t, nums_set.insert(t);

        vector<int> nums(nums_set.begin(), nums_set.end());
        sort(nums.begin(), nums.end());
        int left = 0;
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] - nums[left] > ori_size-1) left++;
            res = max(res, i - left + 1);
        }

        cout << res << '\n';
    }

    return 0;
}