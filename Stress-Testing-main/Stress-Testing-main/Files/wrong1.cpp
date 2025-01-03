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
vector<ll> primes;
ll MAXN = 1e8;

void doSieve() {
    vector<bool> sieve(MAXN+1, true);
    for (ll i = 2; i < sieve.size(); i++) {
        if (!sieve[i]) {
            continue;
        }
        primes.push_back(i);
        for (ll j = i*2; j < sieve.size(); j+=i) {
            sieve[j] = false;
        }
    }
}

void solve() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    ll ori = n;
    ll res = 1;
    for (ll i : primes) {
        if (i*i > n) {
            break;
        }

        ll exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }

        ll tot = 1, div = 1;
        while (exp-- > 0) {
            div *= i;
            tot += div;
        }

        res *= tot;
    }

    if (n > 1) {
        res *= (n+1);
    }
    res -= ori;

    cout << res << '\n';
}

int main() {
    int TC = 1;
    cin >> TC;
    doSieve();
    while (TC--) {
        solve();
    }
    
    return 0;
}