// Use factorial number system, which is represented by: c_n * n! + c_(n-1) * (n-1)! + ... + c_2 * 2! + c_1 * 1! + c_0 * 0!, 
// where 0 <= c_n <= n.
// We can get ord(), which is the index of the permutation, by observing and getting the formula 
// ord(p) = sum r from n to 0 (how many elements < arr[r]) * r!.
// For example, 0 1 2 3 -> 0*3! + 0*2! + 0*1! + 0*0! = 0, 
//              0 1 3 2 -> 0*3! + 0*2! + 1*1! + 0*0! = 1.
// To get these index, we can use segment tree to retrieve the number of element < arr[r].
// After getting index for the two permutations, 
// we can get add the index element-wise to get the index for the new permutation. 
// new_index[i] = (a_index[i] + b_index[i]) % modulo, 
// coeff  = 3! 2! 1! 0!
// modulo = 4  3  2  1
// To get back the permutation perm(), 
// we can iterate through the index array and use segment tree and binary search to 
// retrieve the smallest index[i] element.

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

vector<int> tree;
int old_n;

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

vector<int> ord(int n, vector<int>& arr) {
    while (__popcount(n) != 1) {
        arr.push_back(-1);
        n++;
    }
    tree.assign(n*2, 0);

    for (int i = 0; i < n; i++) {
        if (arr[i] == -1) {
            break;
        }

        tree[i+n] = 1;
    }

    for (int i = n-1; i >= 1; i--) {
        tree[i] = tree[i*2] + tree[i*2+1];
    }

    vector<int> res(old_n);
    for (int i = old_n-1; i >= 0; i--) {
        res[old_n-1-i] = query(1, 0, n-1, 0, arr[old_n-i-1]-1);
        update(1, 0, n-1, arr[old_n-i-1], arr[old_n-i-1], 0);
    }

    return res;
}

vector<int> perm(vector<int>& added) {
    tree.assign(tree.size(), 0);
    for (int i = tree.size()/2; i < tree.size()/2+old_n; i++) {
        tree[i] = 1;
    }

    for (int i = tree.size()/2-1; i >= 1; i--) {
        tree[i] = tree[i*2] + tree[i*2+1];
    }
    vector<int> res;

    for (auto x : added) {
        int lo = 0, hi = old_n;
        // DEBUGV(tree);
        x++;
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            if (query(1, 0, tree.size()/2-1, 0, m) >= x) {
                hi = m;
            } else {
                lo = m + 1;
            }
        }

        res.push_back(lo);
        update(1, 0, tree.size()/2-1, lo, lo, 0);
    }

    return res;
}

void solve() {
    int n;
    cin >> n;
    old_n = n;
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }
    
    vector<int> coeff1 = ord(n, arr1);
    vector<int> coeff2 = ord(n, arr2);
    vector<int> added(coeff1.size());
    int carry = 0;
    for (int i = coeff1.size()-2; i >= 0; i--) {
        added[i] = (coeff1[i] + coeff2[i] + carry) % (coeff1.size()-i);
        carry = (coeff1[i] + coeff2[i] + carry) / (coeff1.size()-i);
    }
    // DEBUGV(coeff1);
    // DEBUGV(coeff2);
    // DEBUGV(added);
    vector<int> res = perm(added);
    // DEBUGV(res);

    for (auto x : res) {
        cout << x << ' ';
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