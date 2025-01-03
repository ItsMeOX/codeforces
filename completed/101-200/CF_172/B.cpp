// Simulate the process.
// It is optimal to pick the marble with count of 1 first.
// Then after we pick, check if next least marble is 1 or not, 
// if not then we get 1 point from picking 1, 
// otherwise we get 0 point as the enemy will take it.

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

void solve() {
    int n;
    cin >> n;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto [k, v] : mp) {
        pq.push(v);
    }

    int res = 0;
    while (!pq.empty()) {
        int x = pq.top();
        pq.pop();
        if (x == 1) {
            res += 2;
        } else {
            res++;
        }

        if (!pq.empty()) {
            int y = pq.top();
            if (y != 1) {
                res++;
            }
            pq.pop();
        }
    }

    cout << res << '\n';
}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}