// Let suffix[i] be count(1) - count(0) from i to n.
// Whenever we split a group at index i, ans will increase by suffix[i].
// In order to get minimum group, we shall choose the suffix with the largest value first.

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
    string s;
    cin >> s;

    vector<int> suffix(n);
    suffix[n-1] = (s[n-1] == '1' ? 1 : -1);
    for (int i = n-2; i >= 1; i--) {
        suffix[i] = suffix[i+1] + (s[i] == '1' ? 1 : -1);
    }
    sort(suffix.begin(), suffix.end());

    int grp = 0;
    ll cum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (suffix[i] <= 0) {
            break;
        }
        cum += suffix[i];
        grp++;
        if (cum >= k) {
            cout << (grp+1) << '\n';
            return;
        }
    }

    cout << -1 << '\n';

}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}