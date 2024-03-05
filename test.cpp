#include <bits/stdc++.h>
using namespace std;

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