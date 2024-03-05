#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// For kth query which k > 0,
// as Masha and Olya takes turn to perform the operation, we can observe that when it is Masha's turn, 
// the number of odd number will -2,
// for Olya, the number of odd number will -1.
// So the pattern is -1 -2 -1 -2 -1 -2,
// every time it is Olya's turn, we will -1 from the total sum from nums[0 ~ k].
// The number of turn of Olya will be number of odds / 3. (if there is no more odd number then it is equivalent to always Masha's turn)
// If we have nums like 2 1 6, where number of odds % 3 == 1, then we will have to -1 from sums too.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int t;
        cin >> t;

        vector<int> nums(t);
        for (int i = 0; i < t; i++) cin >> nums[i];

        cout << nums[0] << ' ';

        int odds = nums[0] & 1;
        long long sums = nums[0];
        for (int i = 1; i < t; i++) {
            if (nums[i] & 1) odds++;
            sums += nums[i];
            cout << sums - (odds/3) - (odds%3 == 1) << ' ';
        }
        cout << '\n';
    }

    return 0;
}