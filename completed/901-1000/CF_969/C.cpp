// For a == b, 
// we can keep incrementing the smallest element by a until it is closest to the largest element, 
// we can do all arr[i]%a, then res = min(res, arr[i-1]+a-arr[i]).
// For a != b, 
// we can keep incrementing the smallest element by gcd(a, b), 
// because by Bezout's theorem, ax + by = gcd(a, b), any linear combination of a and b is multiple of gcd(a, b), 
// and we can increase minimally a step of gcd(a, b) by tweaking the values a and b.

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int g = __gcd(a, b);
    for (int i = 0; i < n; i++) {
        arr[i] %= g;
    }
    sort(arr.begin(), arr.end());

    int res = arr.back() - arr[0];
    for (int i = 1; i < n; i++) {
        res = min(res, arr[i-1]+g-arr[i]);
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