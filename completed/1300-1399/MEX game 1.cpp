#include <bits/stdc++.h>
using namespace std;


// If count(num) >= 2, then Alice always can pick it.
// Alice only cannot pick the second num with count(num) == 1 from sorted nums.
// If count(num) == 0, it is a candidate answer also.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> nums(n+1);

        int t;
        for (int i = 0; i < n; i++) {
            cin >> t;
            nums[t]++;
        }

        int count = 0;
        for (int i = 0; i <= n; i++) {
            count += (nums[i] == 1);
            if (nums[i] == 0 || count == 2) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
