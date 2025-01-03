// The target of the pseudocode is to get for every subarray of array a which has length of array b, 
// if the any permutation of subarray a and array b satisfy for all a[i] + b[i] >= h, then add 1 to res.
// To optimize this algorithm, 
// we can sort array b in decreasing order and subarray a in increasing order, and check if all a[i] + b[i] >= h.
// To make this O(nlogn), 
// we can utilize sliding window + segment tree.
// We set segment tree to be: 
// [b.size, b.size-1, ..., 2, 1], 
// then when we insert element from array a to current window, 
// we binary search for the smallest element in array b where b[i] + a[i] >= h, 
// and we subtract 1 from 0~index in segment tree.
// To remove element from current window, 
// we add 1 from 0~index in segment tree.
// Then for every window of length b.size, 
// we query for minimum element in segment tree, if it is >= 0, add 1 to res.

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

vector<ll> tree, lazy;
 
ll query(int node, int l, int r, int ql, int qr) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        
        if (l != r) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if (l > qr || r < ql) {
        return 0;
    }
 
    if (l >= ql && r <= qr) {
        return tree.at(node);
    }
 
    ll mid = (l + r) / 2;
    return min(query(node*2, l, mid, ql, qr), query(node*2+1, mid+1, r, ql, qr));
}
 
void update(int node, int l, int r, int ql, int qr, int v) {
    if (lazy[node] != 0) {
        tree[node] += lazy[node];
        
        if (l != r) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
 
    if (l > qr || r < ql) {
        return;
    }
 
    if (ql <= l && r <= qr) {
        tree[node] += v;
        if (l != r) {
            lazy[node*2] += v;
            lazy[node*2+1] += v;
        }
        return;
    }
 
    ll md = l + (r - l) / 2;
    update(node*2, l, md, ql, qr, v);
    update(node*2+1, md+1, r, ql, qr, v);
 
    tree[node] = min(tree[node*2], tree[node*2+1]);
}

void solve() {
    ll n, len, h;
    cin >> n >> len >> h;

    vector<ll> b(len);
    vector<ll> a(n);

    for (int i = 0; i < len; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    while (__popcount(len) != 1) {
        len++;
    }

    tree.resize(len*2, LLONG_MAX);
    lazy.resize(len*2);

    for (int i = 0; i < b.size(); i++) {
        tree[i+len] = b.size()-i;
    }
    for (int i = len-1; i >= 1; i--) {
        tree[i] = min(tree[i*2], tree[i*2+1]);
    }

    // DEBUGV(tree);
    // DEBUGV(lazy);
    // cout << '\n';

    sort(b.begin(), b.end());
    vector<bool> skip(a.size());
    int skip_count = 0;
    int res = 0;
    int bs = b.size();
    for (int i = 0; i < n; i++) {
        if (i-bs >= 0) {
            if (skip[i-bs]) {
                skip_count--;
            } else {
                // cout << "WTF" << ' ' << i << ' ' << bs << ' ' << i-(int)bs << '\n';
                int idx = lower_bound(b.begin(), b.end(), h-a[i-bs]) - b.begin();
                update(1, 0, len-1, 0, idx, 1);
            }
        }
        // DEBUG(i);
        // DEBUGV(tree);
        // DEBUGV(lazy);

        auto it = lower_bound(b.begin(), b.end(), h-a[i]);
        // DEBUG(h-a[i]);
        if (it == b.end()) {
            skip[i] = 1;
            skip_count++;
            continue;
        }

        int idx = it - b.begin();
        update(1, 0, len-1, 0, idx, -1);
        // DEBUG(i);
        // DEBUGV(tree);
        // DEBUGV(lazy);
        // cout << '\n';

        if (skip_count > 0) {
            continue;
        }

        if (i >= bs-1 && query(1, 0, len-1, 0, len-1) >= 0) {
            res++;
        }
    }
    // DEBUGV(skip);

    cout << res;
}

int main() {
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}