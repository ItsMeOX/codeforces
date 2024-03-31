#include <bits/stdc++.h>
using namespace std;


// TODO: why m <= n does not work for the formulas.
// Can m - (case of k=2), no need to derive formula for k = 3.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        long long n, m, k;
        cin >> n >> m >> k;

        long long res = 0;
        if (k == 2) {
            cout << (m <= n ? m : 1LL*n + m/n - 1) << '\n';
        } else if (k == 3) {
            cout << (m <= n ? 0 : 1LL*m - (n + m/n - 1)) << '\n';
            // cout << max(1LL*((m-1)/n - 1) * (n-1) + (m%n ? m%n : 2), 0LL) << '\n';
            // int complete = max(m/n, 0);
            // cout << complete * (n-1) + m%n << '\n';
        } else if (k == 1) {
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }

    }

    return 0;
}