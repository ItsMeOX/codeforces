#include <bits/stdc++.h>
using namespace std;


// Use prefix sum for each index i and check if left and right array satisfies the two condtions.
// Get the least distance among all the positions that satisfiy the condition.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int left_zero = 0;
        vector<int> right_one(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            right_one[i] = right_one[i+1] + (s[i] == '1');
        }

        int min_dist = INT_MAX;
        int res = -1;

        for (int i = 0; i <= n; i++) {
            if (left_zero >= (i+1)/2 && right_one[i] >= (n-i+1)/2) {
                if (abs(n - 2*i) < min_dist) {
                    min_dist = abs(n-2*i);
                    res = i;
                }
            }

            if (i < n)
                left_zero += s[i] == '0';

        }

        cout << res << '\n';
    }

    return 0;
}