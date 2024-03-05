#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Take example of "abaca", we can observe that two 'a' can be paired with other characters with one 'a' left over.
// (it is optimal to pair all the letters with larger frequency first)
// So, we can take the max frequency of a letter from s, then pair them first, 
// the number of pairable will be count(largest freq) - count(other chars). We take max(maxCnt - avail, 0) to prevent -ve number here.
// Lastly, note that if we paired all the numbers and the length of s is odd, then we have to add 1 to our res.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int sz;
        cin >> sz;
        vector<char> s(sz, 0);

        for (int i = 0; i < sz; i++)
            cin >> s[i];

        vector<int> counter(26, 0);
        for (auto& c : s) counter[c-'a']++;

        int maxCnt = *max_element(counter.begin(), counter.end());
        int avail = sz - maxCnt;
        int res = max(maxCnt - avail, 0);

        if (res == 0 && (sz & 1)) res++;

        cout << res << '\n';
    }

    return 0;
}