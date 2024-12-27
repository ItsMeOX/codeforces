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
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    ll res = n / (a + b + c) * 3;
    ll remain = n % (a + b + c);
    vector<ll> arr{a, b, c};
    int i = 0;
    while (remain > 0) {
        remain -= arr[i];
        i = (i + 1) % arr.size();
        res++;
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