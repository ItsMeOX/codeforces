#include <bits/stdc++.h>
using namespace std;


// We just need to check indices mat[0~m/2][0~m/2].
// For one index, the next indices after rotating will be: (r, c), (c, m-r-1), (m-r-1, m-c-1), (m-c-1, r).
// For the four indices, get the largest alphabet and make the other three become this alphabet.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int m;
        cin >> m;
        char t;

        vector<vector<int>> mat(m, vector<int>(m));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < m; c++) {
                cin >> t;
                mat[r][c] = t-'a';
            }
        }
        int res = 0;
        int largest;

        for (int r = 0; r < m/2; r++) {
            for (int c = 0; c < m/2; c++) {
                largest = max({mat[r][c], mat[c][m-r-1], mat[m-r-1][m-c-1], mat[m-c-1][r]});
                res += (4 * largest - mat[r][c] - mat[c][m-r-1] - mat[m-r-1][m-c-1] - mat[m-c-1][r]);
            }
        }

        cout << res << '\n';
    }

    return 0;
}