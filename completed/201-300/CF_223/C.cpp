// (())
// It is best to pair ) with the closest ( from the left.
// In a segment, the number of subsequence of complete paranthesis is the number of '(' that comes before ')'.
// Use a segment tree to keep track of closest '(' from each ')', 
// then for each query, for each ')', find the number of '(' that is in current query segment.

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

vector<vector<int>> tree;
 
ll query(int node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
 
    if (l >= ql && r <= qr) {
        return tree[node].end() - lower_bound(tree[node].begin(), tree[node].end(), ql);
    }
 
    ll mid = (l + r) / 2;
    ll res = query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);
    return res;
}
 
// void update(int node, int l, int r, int ql, int qr, int v) {
//     if (l > qr || r < ql) {
//         return;
//     }
 
//     if (ql <= l && r <= qr) {
//         tree[node] = v;
//         return;
//     }
 
//     ll md = l + (r - l) / 2;
//     update(node*2, l, md, ql, qr, v);
//     update(node*2+1, md+1, r, ql, qr, v);
 
//     tree[node] = tree[node*2] + tree[node*2+1];
// }


void solve() {
    int q;
    string s;
    cin >> s;
    cin >> q;
    int n = s.length();

    stack<int> stk;
    vector<int> arr(n, INT_MAX);

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk.push(i);
        } else if (!stk.empty()) {
            arr[i] = stk.top();
            stk.pop();
        }
    }

    while (__popcount(n) != 1) {
        arr.push_back(INT_MAX);
        n++;
    }

    tree.resize(n*2);

    for (int i = 0; i < n; i++) {
        if (arr[i] != INT_MAX) {
            tree[i+n].push_back(arr[i]);
        }
    }

    for (int i = n-1; i >= 1; i--) {
        for (auto x : tree[i*2]) {
            tree[i].push_back(x);
        }
        for (auto x : tree[i*2+1]) {
            tree[i].push_back(x);
        }
        sort(tree[i].begin(), tree[i].end());
    }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        cout << query(1, 0, n-1, a, b)*2 << '\n';
    }
}

int main() {
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}