// Precompute the space needed if we place a before b.
// We need b to shrink before a expand so we will have the extra space.
// So to compute space, whenever we have + of a before - of b, then we will need one more space. 
// Then we use bit mask dp to try to place ith snake sequentially.
// After we put all the snakes, remember to add the space the last snake will expand to our res.

#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printIterable(const T& container) {
    cout << "[";
    for (auto it = container.begin(); it != container.end(); ++it) {
        cout << *it;
        if (next(it) != container.end()) cout << ", ";
    }
    cout << "]" << endl;
}

#define DEBUG(var) std::cout << #var << " : " << var << std::endl
#define DEBUGV(var) cout << #var << " : "; printIterable(var)

#define ll long long

const int mod = 1e9 + 7;

int n, q;
vector<pair<int, char>> arr;
vector<int> expand;
vector<vector<int>> space;
const int upper = 1e9;
ll dp[1 << 20][21];

ll dfs(int mask, int prev) {
    if (mask == ((1 << n) - 1)) {
        return expand[prev];
    }

    if (dp[mask][prev] != -1) 
        return dp[mask][prev]; 

    ll res = LLONG_MAX;
    for (int j = 0; j < n; j++) {
        if (mask & (1 << j)) {
            continue;
        }

        res = min(res, space[prev][j] + 1 + dfs(mask | (1 << j), j));
    }

    return dp[mask][prev] = res;
}

void solve() {
    cin >> n >> q;
    arr.resize(q);
    expand.resize(n);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < q; i++) {
        cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        if (arr[i].second == '+') {
            expand[arr[i].first]++;
        }
    }

    space.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int delta = 0;
            int need = 0;
            for (auto& [idx, sig] : arr) {
                if (idx == j && sig == '-') {
                    delta--;
                } else if (idx == i && sig == '+') {
                    delta++;
                    if (delta > 0) {
                        delta = 0;
                        need++;
                    }
                }
            }
            space[i][j] = need;
        }
    }

    ll res = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        ll cur = dfs(1 << i, i) + 1;
        if (cur > upper) {
            continue;
        }
        res = min(res, cur);
    }
    cout << res;
}

int main() {
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}