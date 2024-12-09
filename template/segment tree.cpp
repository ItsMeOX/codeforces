#include <bits/stdc++.h>
using namespace std;
# define ll long long

vector<ll> tree;
 
ll query(int node, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
 
    if (l >= ql && r <= qr) {
        return tree.at(node);
    }
 
    ll mid = (l + r) / 2;
    ll res = query(node*2, l, mid, ql, qr) + query(node*2+1, mid+1, r, ql, qr);
    return res;
}
 
void update(int node, int l, int r, int ql, int qr, int v) {
    if (l > qr || r < ql) {
        return;
    }
 
    if (ql <= l && r <= qr) {
        tree[node] = v;
        return;
    }
 
    ll md = l + (r - l) / 2;
    update(node*2, l, md, ql, qr, v);
    update(node*2+1, md+1, r, ql, qr, v);
 
    tree[node] = tree[node*2] + tree[node*2+1];
}

int main() {
    ll n;
    vector<ll> arr(n);

    // < input... >

    while (__builtin_popcount(n) != 1) {
        arr.push_back(0);
        n++;
    }
    tree.resize(n*2);
 
    for (int i = 0; i < n; i++) {
        tree[i+n] = arr[i];
    }
 
    for (int i = n-1; i >= 1; i--) {
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}