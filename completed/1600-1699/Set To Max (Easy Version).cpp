#include <bits/stdc++.h>
using namespace std;


// Transform array a to b from the number with the smallest value first,
// for each idx i, traverse j to left and right to get j where a[j] == b[i].
// During the traversal, 
// 1. if we encounter a[j] == b[i], break and we have a ans,
// 2. if we encounter number larger than b[i], then ans is no, as the whole range will be replaced by this larger number,
// 3. if we encounter smaller number, then ans is no, as we will change the already fixed smaller number.
// After the traversal, we need to simulate and replace [left, right] to b[i],
// and if after traversal a[i] != b[i], then the ans is no.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int sz;
        cin >> sz;

        vector<int> a(sz, 0);
        vector<int> b(sz, 0);
        vector<int> idx(sz, 0);

        for (int i = 0; i < sz; i++) cin >> a[i];
        for (int i = 0; i < sz; i++) cin >> b[i];
        for (int i = 0; i < sz; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&b](auto x, auto y){return b[x] < b[y];});
        bool res = true;

        for (auto i : idx) {
            if (a[i] == b[i]) continue;
            if (a[i] > b[i]) {
                res = false;
                cout << "NO\n";
                break;
            }

            int left = -1, right = -1;

            for (int j = i-1; j >= 0; j--) {
                if (b[j] < b[i] || a[j] > b[i]) break;
                if (a[j] == b[i]) {
                    left = j;
                    break;
                } 
            }

            if (left != -1)
            for (int j = i; j >= left; j--) {
                a[j] = b[i];
            }

            for (int j = i+1; j < sz; j++) {
                if (b[j] < b[i] || a[j] > b[i]) break;
                if (a[j] == b[i]) {
                    right = j;
                    break;
                }
            }

            if (right != -1)
            for (int j = i; j <= right; j++) {
                a[j] = b[i];
            }

            if (a[i] != b[i]) {
                res = false;
                cout << "NO" << '\n';
                break;
            }

        }

        if (res)
            cout << "YES" << '\n';
    }

    return 0;
}