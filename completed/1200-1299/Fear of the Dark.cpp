#include <bits/stdc++.h>
using namespace std;


// if P in circle B:
//    check if (O is also in B) or (O in A and AB connected)
// else if P in circle A:
//    check if (O is also in A) or (O in B and AB connected)

// Use binary search to search for this condition, and break when right-left is smaller than a threshold.
// Remember to set precision when outputting answer.

int main() {
    int tc;
    cin >> tc;

    while (tc--) {
        int Px, Py, Ax, Ay, Bx, By;
        cin >> Px >> Py >> Ax >> Ay >> Bx >> By;

        double left = 0, right = 10000;
        double mid;
        bool PB, PA, AB, OA, OB;

        while (right - left > 0.00000001) {
            mid = left + (right-left)/2;
            bool can = false;

            OA = (pow(Ax, 2) + pow(Ay, 2)) <= pow(mid, 2); // O is in A
            OB = (pow(Bx, 2) + pow(By, 2)) <= pow(mid, 2); // O is in B
            PA = (pow(Ax-Px, 2) + pow(Ay-Py, 2)) <= pow(mid, 2); // P is in A
            PB = (pow(Bx-Px, 2) + pow(By-Py, 2)) <= pow(mid, 2); // P is in B
            AB = (pow(Ax-Bx, 2) + pow(Ay-By, 2)) <= pow(2*mid, 2); // AB are connected

            if (PB) {
                can = OB || (OA && AB);
            } else if (PA) {
                can = OA || (OB && AB);
            }

            if (can) 
                right = mid;
            else
                left = mid;
        }

        cout << setprecision(10) << mid << '\n';
    }

    return 0;
}