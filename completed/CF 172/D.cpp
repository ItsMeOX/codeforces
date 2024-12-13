// Sort the segments by: 
// start -> increasing order
// end   -> decreasing order
// so that when we process ith segment, we will have processed all of its predictors.
// For each segment [a, b], 
// we get the minimum end of all predictors that is >= b, then we can add min_end - b to res.
// We can do this by maintaining a set and add 'b' to set for every segments, then binary search for 
// min_end that is >= b in the set.
// For a - max_start, we can reflect the segments, and process the same as min_end - b.
// To reflect the segments, we can do [a, b] -> [-b, -a], for example [1, 2] -> [-2, -1].
// Note that when there are >= 2 same segments, we shall make sure that we add all of their 'b's 
// before processing it.

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
    int n;
    cin >> n;
    vector<pair<ll, pair<ll, ll>>> arr(n); // {start, {end, i}}
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second.first;
        arr[i].second.second = i;
    }

    sort(arr.begin(), arr.end(), [&](pair<ll, pair<ll, ll>>& a, pair<ll, pair<ll, ll>>& b) {
        return a.first == b.first ? a.second.first > b.second.first : a.first < b.first;
    });

    set<ll> ending;
    vector<ll> res(n);
    for (int i = 0; i < n; i++) {
        int a = arr[i].first, b = arr[i].second.first, j = arr[i].second.second;
        if (i < n-1 && arr[i+1].first == a && arr[i+1].second.first == b) {
            ending.insert(b);
            continue;
        }
        auto it = ending.lower_bound(b);
        if (it != ending.end()) {
            res[j] += *it - b;
        }
        ending.insert(b);
    }

    for (int i = 0; i < n; i++) {
        arr[i].first = -arr[i].first;
        arr[i].second.first = -arr[i].second.first;
        swap(arr[i].first, arr[i].second.first);
    }
    sort(arr.begin(), arr.end(), [&](pair<ll, pair<ll, ll>>& a, pair<ll, pair<ll, ll>>& b) {
        return a.first == b.first ? a.second.first > b.second.first : a.first < b.first;
    });

    ending.clear();

    for (int i = 0; i < n; i++) {
        int a = arr[i].first, b = arr[i].second.first, j = arr[i].second.second;
        if (i < n-1 && arr[i+1].first == a && arr[i+1].second.first == b) {
            ending.insert(b);
            continue;
        }
        auto it = ending.lower_bound(b);
        if (it != ending.end()) {
            res[j] += *it - b;
        }
        ending.insert(b);
    }


    for (int i = 0; i < n; i++) {
        cout << res[i] << '\n';
    }
}

int main() {
    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve();
    }
    
    return 0;
}