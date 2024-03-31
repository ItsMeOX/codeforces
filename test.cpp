#include <bits/stdc++.h>
using namespace std;


int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];

        int prev = -1;
        int flag = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] < prev) {
                flag = 0;
                break;
            }
            if (nums[i] > 9) {
                int first = nums[i]/10, second = nums[i] % 10;
                if (first >= prev && second >= prev && second >= first)
                    prev = second;
                else
                    prev = nums[i];
            } else {
                prev = nums[i];
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }


    return 0;
}
