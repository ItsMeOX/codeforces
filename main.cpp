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
int m = 0, n = 0;
set<pair<int, int>> seen;
vector<string> arr;
bool isOut(int r, int c) {
    return r < 0 || r >= m || c < 0 || c >= n;
}

void solve() {
    string s;
    unordered_map<char, vector<pair<int, int>>> mp;
    while (getline(cin, s)) {
        for (int c = 0; c < s.length(); c++) {
            if (s[c] != '.') {
                mp[s[c]].push_back({m, c});
            }
        }
        m++;
        arr.push_back(s);
    }
    n = arr[0].length();

    int res = 0;
    for (auto& [sig, pos] : mp) {
        for (int i = 0; i < pos.size(); i++) {
            for (int j = i+1; j < pos.size(); j++) {
                int dr = pos[j].first - pos[i].first;
                int dc = pos[j].second - pos[i].second;
                int nr1 = pos[i].first - dr, nc1 = pos[i].second - dc;
                int nr2 = pos[j].first + dr, nc2 = pos[j].second + dc;
                if (!seen.count({pos[i].first, pos[i].second})) {
                    seen.insert({pos[i].first, pos[i].second});
                    res++;
                }
                if (!seen.count({pos[j].first, pos[j].second})) {
                    seen.insert({pos[j].first, pos[j].second});
                    res++;
                }
                while (!isOut(nr1, nc1)) {
                    if (!seen.count({nr1, nc1})) {
                        seen.insert({nr1, nc1});
                        res++;
                    }
                    nr1 -= dr;
                    nc1 -= dc;
                }
                while (!isOut(nr2, nc2)) {
                    if (!seen.count({nr2, nc2})) {
                        seen.insert({nr2, nc2});
                        res++;
                    }
                    nr2 += dr;
                    nc2 += dc;
                }
            }
        }
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