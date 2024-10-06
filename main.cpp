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

int main() {
    int tc, t=0;
    cin >> tc;
    int N;

    while (t++ < tc) {
        cin >> N;
        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }



        cout << "Case #" << t << ": " << res << '\n';
    }

    return 0;
}

// (17 + x) % 7 == 0

6 3 x 2 5 4

// (20 + x) % 10 == 0