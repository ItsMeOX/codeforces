// For p_i and p_(i+1) to be composite, 
// we can put all the odd numbers to the left of the array, 
// then fill with even numbers to the right of the array. 
// To make sure that the middle point where the odd and even number touch is composite, 
// we assign the two positions with smallest odd and even number whose sum will be composite, 
// here we choose 4 and 5, 
// because notice that when n <= 4, the answer will -1.
// Extra: 
// Sum of any pair of prime number where a prime is > 2, the result will be composite, because 
// any prime number > 2 is odd.

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
    if (n <= 4) {
        cout << -1 << '\n';
        return;
    }

    vector<int> res(n);
    res[n/2-1] = 4;
    res[n/2] = 5;
    int cur = 2;
    for (int i = 0; i < n/2-1; i++) {
        res[i] = cur;
        cur += 2;
        if (cur == 4) {
            cur += 2;
        }
    }
    cur = 1;
    for (int i = n/2+1; i < n; i++) {
        res[i] = cur;
        cur += 2;
        if (cur == 5) {
            cur += 2;
        }
    }

    for (auto x : res) {
        cout << x << ' ';
    }
    cout << '\n';

}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}