// Keep picking the largest valued chest, 
// if the next chest + cur > k, then stop and add value to current chest.

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

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur + arr[i] > k) {
            break;
        }
        cur += arr[i];
    }

    cout << k - cur << '\n';
}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}