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
        if (s.count(1)) {
            has_nei.insert(1);
        }
        if (s.count(n)) {
            has_nei.insert(n);
        }
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
// int solve2() {
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<pair<int, int>> segs({{1, -q}, {m, m}, {n + q + 1, n}});
//     while (q--) {
//       int x;
//       cin >> x;
//       bool ins = false;
//       for (auto& [l, r] : segs) {
//         if (x < l) l = max(1, l - 1);
//         else if (x > r) r = min(n, r + 1);
//         else {
//           ins = true;
//           if (l == r) l = n + q, r = -q;
//         }
//       }
//       if (ins) {
//         segs[0] = {1, max(segs[0].second, 1)};
//         segs[2] = {min(segs[2].first, n), n};
//       }
//       int lf = 0, rg = -1, ans = 0;
//     for (auto [l, r] : segs) {
//         if (l > r) continue;
//         if (l > rg) {
//           ans += max(0, rg - lf + 1);
//           lf = l; rg = r;
//         }
//         rg = max(rg, r);
//       }
//       ans += max(0, rg - lf + 1);
//       DEBUG(ans);
//     }
//      cout << '\n';
// }
int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve(); 
        // cout << '\n';
        // solve2();
    }
    
    return 0;
}