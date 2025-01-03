// For case:
// 4 3
// 2 3 2 8
// 3 7 3 9
// We can rearrange price by:
// price : 2 2 3 3 3 7 8 9
// a or b: a a a b b b b b
// neg   : 0 0 0 2 2 ...
// at ith index, 
// neg = count(a) - count(b), 
// and we can have income of (n - count(b)) * price_i.

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
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> prices;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prices.push_back({x, 0});
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        prices.push_back({x, 1});
    }

    sort(prices.begin(), prices.end());

    ll res = 0;
    int prev_a = 0, prev_b = 0, prev_price = 0;
    int a = 0, b = 0;
    for (auto& [price, t] : prices) {
        if (price > prev_price) {
            a += prev_a;
            b += prev_b;
            prev_a = 0;
            prev_b = 0;
            prev_price = price;
        }

        if (t == 0) {
            prev_a++;
        } else {
            prev_b++;
        }

        int neg = a - b;
        if (neg <= k) {
            res = max(res, 1LL * price * (n - b));
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