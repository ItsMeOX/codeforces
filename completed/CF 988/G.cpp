// Let dp[i] = number of ways to reach from arr[0] to i.
// Base case: dp[all factors of arr[0]] = 1.
// Then for each elements ai, i > 0, 
// we can dp[i] += sum(dp[all factors of arr[i]]), 
// but this would cause overcount, 
// for example, arr = [2, 6, 3, 6], 
// for i = 3 (0-indexed), dp[6] = dp[2] + dp[3] + dp[6], 
// but dp[2] = 2, dp[3] = 2, dp[6] = 1, after summing, we would get 5, which is more than the correct answer of 3.
// To solve the problem of overcounting, we can use inclusion exclusion principle, 
// we iterate through all the subsets of distinct prime factors of arr[i], 
// if len(subsets) is odd, then we add all dp in the subset, otherwise we subtract all dp values in the subset.
// So, dp[6] = dp[2] + dp[3] - dp[6] = 2 + 2 - 1 = 3.

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

const int mod = 998244353;
int n;
vector<int> arr;
vector<ll> dp;

vector<bool> is_prime(1e6+1, true);
void sieve() {
    for (int i = 2; i <= is_prime.size(); i++) {
        if (!is_prime[i]) {
            continue;
        }
        for (int j = i*2; j < is_prime.size(); j += i) {
            is_prime[j] = false;
        }
    }
}

ll combi(vector<int>& pf) {
    // Get all subsets of the prime factors
    int count = 1 << pf.size();
    ll res = 0;
    for (int mask = 1; mask < count; mask++) {
        ll cur = 1;
        for (int i = 0; i < pf.size(); i++) {
            if (!(mask & (1 << i))) {
                continue;
            }
            cur *= pf[i];
            cur %= mod;
        }
        // assert(cur < dp.size());
        if (__popcount(mask) & 1) {
            res += dp[cur];   
        } else {
            res -= dp[cur];
            // Getting rid of -ve result after modding...
            if (res < 0) {
                res += mod;
            }
        }
        res %= mod;
    }

    return res;
}

pair<vector<int>, vector<int>> getFactors(int x) {
    vector<int> pf; // prime factors
    vector<int> f{x}; // factors
    if (is_prime[x]) {
        pf.push_back(x);
    }

    for (int j = 2; j*j <= x; j++) {
        if (x % j == 0) {
            f.push_back(j);
            if (is_prime[j]) {
                pf.push_back(j);
            }

            f.push_back(x/j);
            if (is_prime[x/j]) {
                pf.push_back(x/j);
            }
        }
    }

    sort(pf.begin(), pf.end());
    pf.erase(unique(pf.begin(), pf.end()), pf.end());
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());

    return {pf, f};
}

void solve() {
    cin >> n;
    arr.resize(n);
    
    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }

    dp.resize(mx+1);
    auto [pf, f] = getFactors(arr[0]);
    for (auto x : f) {
        dp[x]++;
    }
    ll res = -1;
    // DEBUGV(dp);

    for (int i = 1; i < arr.size(); i++) {
        auto [pf, f] = getFactors(arr[i]);

        // DEBUGV(pf);
        // DEBUGV(f);
        ll cur = combi(pf);
        cur %= mod;
        res = cur;
        // DEBUG(cur);

        for (auto x : f) {
            dp[x] += cur;
            dp[x] %= mod;
        }
        // DEBUGV(dp);
    }

    cout << res;
}

int main() {
    sieve();
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}