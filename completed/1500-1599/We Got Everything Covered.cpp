#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// https://codeforces.com/problemset/problem/1924/A

// For every permutation of string made from n and k to exist, we need atleast n segments that contain all the k letters.

// For n = 3, k = 3, s = "aabbccabab",
// we can split s into "aabbcc", "abab", where each segments have n distinct letters.
// Then we can greedily select last letter of every segment, and add it into "res",
// if after adding all the last letters, the length of res is >= n, then all permutations are valid, so print "YES".
// else if len(res) < n, we find the missing character and keep adding the character until length of res == n.

int main() {
    int tc;
    cin >> tc;
    int n,k,m;
    string s;

    while (tc--) {
        cin >> n >> k >> m;
        cin >> s;
        unordered_set<int> vis;
        string res = "";

        for (char& c : s) {

            vis.insert(c);
            if (vis.size() == k) {
                res += c;
                vis.clear();
            }

        }

        if (res.length() >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            for (int i = 0; i < 26; i++) {
                if (!vis.count((char)(i+'a'))) {
                    while (res.size() < n) res += (char)(i+'a');
                }
            }
            cout << res << '\n';
        }

    }

    return 0;
}