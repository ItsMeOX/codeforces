// For each segment, find gcd(all elm in segment), and find the number of element == gcd, 
// because if a number == gcd(all other number), then it will divide all other numbers.

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

vector<int> tree_gcd;
vector<vector<int>> tree;

int query_gcd(int node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
 
    if (l >= ql && r <= qr) {
        return tree_gcd.at(node);
    }
 
    ll mid = (l + r) / 2;
    int res = __gcd(query_gcd(node*2, l, mid, ql, qr), query_gcd(node*2+1, mid+1, r, ql, qr));
    return res;
}

int query(int node, int l, int r, int ql, int qr, int v) {
    if (l > qr || r < ql) {
        return 0;
    }
 
    if (l >= ql && r <= qr) {
        return upper_bound(tree[node].begin(), tree[node].end(), v) - lower_bound(tree[node].begin(), tree[node].end(), v);
    }
 
    ll mid = (l + r) / 2;
    int res = query(node*2, l, mid, ql, qr, v) + query(node*2+1, mid+1, r, ql, qr, v);
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    while (__popcount(n) != 1) {
        arr.push_back(0);
        n++;
    }

    tree.resize(n*2);
    tree_gcd.resize(n*2);

    for (int i = 0; i < n; i++) {
        tree[i+n].push_back(arr[i]);
        tree_gcd[i+n] = arr[i];
    }

    for (int i = n-1; i >= 1; i--) {
        for (auto x : tree[i*2]) {
            tree[i].push_back(x);
        }
        for (auto x : tree[i*2+1]) {
            tree[i].push_back(x);
        }
        sort(tree[i].begin(), tree[i].end());
        tree_gcd[i] = __gcd(tree_gcd[i*2], tree_gcd[i*2+1]);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int g = query_gcd(1, 0, n-1, a, b);
        cout << b - a + 1 - query(1, 0, n-1, a, b, g) << '\n';
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