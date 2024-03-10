#include <bits/stdc++.h>
using namespace std;


// if c = 5
// (x,y) will be:
// (0,0), (0,1), (0,2), (0,3), (0,4), (0,5)
// (1,1), (1,2), (1,3), (1,4), (1,5)
// (2,2), (2,3), (2,4), (2,5)
// (3,3), (3,4), (3,5)
// (4,4), (4,5)
// (5,5)

// x+y will be:
// 0 1 2 3 4 5
// 2 3 4 5 6
// 4 5 6 7
// 6 7 8
// 8 9
// 10

// x-y will be:
// 0 1 2 3 4 5
// 0 1 2 3 4
// 0 1 2 3
// 0 1 2
// 0 1
// 0

// For any arbitary s,
// x+y count s will be s/2+1
// x-y count s will be c-s+1
// for double deduction, we can look through x+y and x-y column by column, 
// and we can see that the repeated s will be all the next odd/even s,
// so repeated count = (odd)*(odd+1)/2 + (even)*(even+1)/2.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n, c;
        cin >> n >> c;
        vector<int> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];

        long long res = 1LL*(c+1)*(c+2)/2;

        // 10 + (- 1 - 3 + 1) + (- 2 - 2 + 1) + (- 2 - 1 + 1)
        int odd = 0, even = 0;

        for (auto val : s) {
            res -= (1LL*val / 2 + 1);
            res -= (1LL*c - val + 1);
            (val & 1) ? odd++ : even++;
        }

        res += (1LL*odd+1)*(odd)/2;
        res += (1LL*even+1)*(even)/2;

        cout << res << '\n';
    }

    return 0;
}