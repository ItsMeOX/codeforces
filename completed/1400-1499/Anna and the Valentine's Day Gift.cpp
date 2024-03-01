#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

// https://codeforces.com/problemset/problem/1931/E
// Get the number of trailing zeros and non-trailing count from every numbers.
// For every count of trailing zeroes, push them into a list and sort them.
// For Anna's turn, we just pop off the largest trailing zero count, as Anna will greedily
// flip the number with the most trailing zeroes.
// For Sasha's turn, we add the trailing zeroes to non-trailing count.
// If at last, non-trailing count > m, then Sasha win else Anna win.

int main() {
    int tc;
    cin >> tc;
    int m, n;

    while (tc--) {
        cin >> n >> m;
        vector<int> a;
        int t;
        while (n--) cin >> t, a.push_back(t);
        int res = 0;

        vector<int> trailing_zero;
        for (auto num : a) {
            int zero = 0;
            while (num % 10 == 0) num /= 10, zero++;
            while (num > 0) num /= 10, res++;
            trailing_zero.push_back(zero);
        }

        sort(trailing_zero.begin(), trailing_zero.end());
        while (trailing_zero.size()) {
            // anna
            trailing_zero.pop_back();

            // sasha
            if (trailing_zero.size()) {
                res += trailing_zero.back();
                trailing_zero.pop_back();
            }
        }

        if (res > m) {
            cout << "Sasha\n";
        } else {
            cout << "Anna\n";
        }

    }

    return 0;
}