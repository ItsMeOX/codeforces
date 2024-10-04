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

int main() {
    int n; 
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll res = LLONG_MAX;

    function<void(int, ll, ll)> dfs = [&](int i, ll left, ll right) -> void {
        if (i == n) {
            res = min(res, abs(left - right));
            return ;
        }

        dfs(i+1, left + a[i], right);
        dfs(i+1, left, right + a[i]);
    };

    dfs(0, 0, 0);

    cout << res;

    return 0;
}