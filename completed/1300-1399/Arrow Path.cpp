#include <bits/stdc++.h>
using namespace std;


// Use bfs and brute force every paths,
// if found is found then YES else NO.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int n;
        cin >> n;

        vector<vector<char>> grid(2, vector<char>(n));

        for (int r = 0; r < 2; r++)
        for (int c = 0; c < n; c++)
            cin >> grid[r][c];

        queue<pair<int, int>> q;
        q.push({0, 0});
        unordered_set<string> visited;    
        visited.insert("0,0");

        bool found = false;

        while (q.size()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == 1 && c == n-1) {
                cout << "YES\n";
                found = true;
                break;
            }

            vector<pair<int, int>> next{{r+1, c}, {r-1, c}, {r, c+1}, {r, c-1}};

            for (auto& [nr, nc] : next) {
                if (nr < 0 || nr >= 2 || nc < 0 || nc >= n) continue;

                if (grid[nr][nc] == '>') {
                    nc++;
                } else {
                    nc--;
                }

                string key = to_string(nr) + ',' + to_string(nc);
                if (!visited.count(key)) {
                    visited.insert(key);
                    q.push({nr, nc});
                }
            }
        }

        if (!found) cout << "NO\n";

    }

    return 0;
}