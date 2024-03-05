#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// If we have an array with mixed odd and even numbers, then we can use 2 as k, and only 0 and 1 will be produced.
// If we have whole odd array, then by try and trial, [1, 3, 5, 7, 9], we can use k = 4, but the problem is that
// the array can be [5, 9, 13], where it will only produce 1 if k = 4,
// but from here we can use k = 8, which and the loop goes on...
// So what we can do is to try all the 2^n as k, where 2^n <= 10^18.
// The same goes for whole even array, we can try 2^n as well.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int sz;
        cin >> sz;
        vector<long long> nums(sz, 0);

        for (int i = 0; i < sz; i++) cin >> nums[i];


        // if mixed array
        unordered_set<long long> set;

        for (auto num : nums) set.insert(num & 1);

        if (set.size() == 2) {
            cout << 2 << '\n';
            continue;
        }

        // for whole odd and even array
        unordered_set<long long> set2;
        for (int i = 1; i <= 60; i++) {
            for (auto num : nums) {
                set2.insert(num % (1LL << i));
            }
            if (set2.size() == 2) {
                cout << (1LL << i) << '\n';
                break;
            }
            set2.clear();
        }
    }

    return 0;
}