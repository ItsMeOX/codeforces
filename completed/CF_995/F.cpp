// Observations: 
// 1. If a_i is above m, then m -> m or m-1 (move a_i to top or bottom).
// 2. If a_i is below m, then m -> m or m+1.
// 3. If a_i is equal m, then m -> 1 or n.
// We can use set to keep track of position that we have discovered.

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
    int n, m, q;
    cin >> n >> m >> q;
    set<int> s;
    s.insert(m);
    // Position that has undiscovered neigbour.
    set<int> has_nei;
    has_nei.insert(m);

    auto check = [&](int a, set<int>& has) {
        if (a <= 0 || a >= n+1) {
            return;
        }

        if (a-1 >= 1 && !s.count(a-1)) {
            has.insert(a);
            return;
        }
        if (a+1 <= n && !s.count(a+1)) {
            has.insert(a);
        }
    };

    for (int i = 0; i < q; i++) {
        int Q;
        cin >> Q;
        set<int> next_has_nei;

        // need this to move 1 to n.
        if (s.count(1)) {
            has_nei.insert(1);
        }

        // need this to move n to 1.
        if (s.count(n)) {
            has_nei.insert(n);
        }

        // if a_i == Q, we can move a_i to 1 or n.
        if (s.count(Q)) {
            has_nei.insert(Q);
        }

        if (has_nei.count(Q)) {
            s.erase(Q);
            if (s.count(Q+1)) {
                has_nei.insert(Q+1);
            }
            if (s.count(Q-1)) {
                has_nei.insert(Q-1);
            }

            s.insert(1);
            check(1, next_has_nei);
            s.insert(n);
            check(n, next_has_nei);
        }

        for (auto x : has_nei) {
            if (x > Q) {
                if (x-1 >= 1) {
                    s.insert(x-1);
                    check(x-1, next_has_nei);
                }
                check(x, next_has_nei);
            } else if (x < Q) {
                if (x+1 <= n) {
                    s.insert(x+1);
                    check(x+1, next_has_nei);
                }
                check(x, next_has_nei);
            }
        }

        has_nei = next_has_nei;
        cout << s.size() << ' ';
    }
    cout << '\n';
}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve(); 
    }
    
    return 0;
}