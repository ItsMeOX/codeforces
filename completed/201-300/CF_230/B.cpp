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

    ll ma = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ma = max(ma, (ll)(sqrt(arr[i]))+1);
    }

    vector<bool> is_prime(ma, true);
    for (ll i = 2; i < is_prime.size(); i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (ll j = i*i; j < is_prime.size(); j += i) {
            is_prime[j] = false;
        }
    }

    set<ll> is_res;
    for (ll i = 2; i < ma; i++) {
        if (is_prime[i]) {
            is_res.insert(i*i);
        }
    }

    for (auto x : arr) {
        if (is_res.count(x)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}