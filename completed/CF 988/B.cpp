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
    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        count[num]++;
    }

    // After taking out two numbers for dimensions, 
    // the remaining count of elements will be the width*height.
    int need = n-2;
    for (int i = 1; i*i <= need; i++) {
        if (need % i != 0) {
            continue;
        }

        if (count[need/i] >= 1 && count[i] >= 1) {
            cout << (need/i) << ' ' << (i) << '\n';
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