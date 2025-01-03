// If gcd(all) == 1, return 0.
// If arr[n-1] = gcd(n, arr[n-1]) == 1, return 1.
// If arr[n-2] = gcd(n-1, arr[n-2]) == 1, return 2.
// Else because gcd(n, n-1) == 1, 
// so we transform arr[n-1] and arr[n-2], and return 3.

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int g = 0;
    for (int i = 0; i < n; i++) {
        g = __gcd(g, arr[i]);
    }

    if (g == 1) {
        cout << 0 << '\n';
        return;
    }

    if (__gcd(g, __gcd(n, arr[n-1])) == 1) {
        cout << 1 << '\n';
        return;
    }

    if (__gcd(g, __gcd(n-1, arr[n-2])) == 1) {
        cout << 2 << '\n';
        return;
    }

    cout << 3 << '\n';
}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}