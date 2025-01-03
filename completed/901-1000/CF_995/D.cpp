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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> arr(n);
    ll total = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        total += arr[i];
    }

    ll res = 0;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int left = lower_bound(arr.begin() + i + 1, arr.end(), total - y - arr[i]) - arr.begin();
        int right = upper_bound(arr.begin() + i + 1, arr.end(), total - x - arr[i]) - arr.begin();

        res += right - left;
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