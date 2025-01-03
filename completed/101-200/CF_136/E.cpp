// Use two pointers for i and j, 
// keep count of each elements in left and right segment trees. 
// we initialize left pointer to be at index 0, and right index to be at index 1, 
// then we iterate left pointer one by one, 
// if inv > k or left == right, we try to move right pointer to right. 
// When removing element (or advancing right pointer), inv -= (no. of elm > nums[j] where j < i) + (no. of elm < nums[j] where j > i).
// When adding element   (or advancing left  pointer), inv += like above.
// If inv <= k, we can have n - right valid pairs, because if we advance right pointer, the inv will only decrease.

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

vector<int> ltree, rtree;
 
int query(int node, int l, int r, int ql, int qr, vector<int>& tree) {
    if (l > qr || r < ql) {
        return 0;
    }
 
    if (l >= ql && r <= qr) {
        return tree.at(node);
    }
 
    int mid = l + (r - l) / 2;
    int res = query(node*2, l, mid, ql, qr, tree) + query(node*2+1, mid+1, r, ql, qr, tree);
    return res;
}
 
void update(int node, int l, int r, int ql, int qr, int v, vector<int>& tree) {
    if (l > qr || r < ql) {
        return;
    }
 
    if (ql <= l && r <= qr) {
        tree[node] += v;
        return;
    }
 
    int md = l + (r - l) / 2;
    update(node*2, l, md, ql, qr, v, tree);
    update(node*2+1, md+1, r, ql, qr, v, tree);
 
    tree[node] = tree[node*2] + tree[node*2+1];
}


void solve() {
    ll n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sorted_arr(arr.begin(), arr.end());
    sort(sorted_arr.begin(), sorted_arr.end());
    sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());

    for (int i = 0; i < n; i++) {
        arr[i] = lower_bound(sorted_arr.begin(), sorted_arr.end(), arr[i]) - sorted_arr.begin();
    }

    while (__popcount(n) != 1) {
        n++;
    }

    ltree.resize(n*2);
    rtree.resize(n*2);

    ll res = 0, inv = 0;
    for (int i = 0; i < arr.size(); i++) {
        update(1, 0, n-1, arr[i], arr[i], 1, rtree);
        inv += query(1, 0, n-1, arr[i]+1, n-1, rtree);
    }
    // DEBUG(inv);

    int j = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (i == j) {
            inv -= query(1, 0, n-1, arr[i]+1, n-1, ltree) + query(1, 0, n-1, 0, arr[i]-1, rtree);
            update(1, 0, n-1, arr[i], arr[i], -1, rtree);
            j++;
        }

        update(1, 0, n-1, arr[i], arr[i], 1, ltree);
        inv += query(1, 0, n-1, arr[i]+1, n-1, ltree) + query(1, 0, n-1, 0, arr[i]-1, rtree);

        while (j < arr.size() && inv > k) {
            inv -= query(1, 0, n-1, arr[j]+1, n-1, ltree) + query(1, 0, n-1, 0, arr[j]-1, rtree);
            // DEBUG(arr[j]);
            // DEBUGV(rtree);
            // DEBUG(query(1, 0, n-1, arr[j]+1, n-1, ltree));
            // DEBUG(query(1, 0, n-1, 0, arr[j]-1, rtree));
            // DEBUG(j);
            // DEBUG(inv);
            update(1, 0, n-1, arr[j], arr[j], -1, rtree);
            j++;
        }

        if (j == arr.size()) {
            break;
        }

        res += arr.size() - j;
    }

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