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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> M(m);
    for (int i = 0; i < m; i++) {
        cin >> M[i];
    }

    set<int> ques;
    for (int i = 1; i <= n; i++) {
        ques.insert(i);
    }
    for (int i = 0; i < k; i++) {
        int a;
        cin >> a;
        ques.erase(a);
    }

    if (ques.size() > 1 || ques.size() == 0) {
        for (int i = 1; i <= m; i++) {
            cout << (ques.size() > 1 ? '0' : '1');
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < m; i++) {
        if (M[i] != *ques.begin()) {
            cout << '0';
        } else {
            cout << '1';
        }
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