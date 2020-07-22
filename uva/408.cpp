#include <bits/stdc++.h>
using namespace std;

int X, Y;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while ((cin >> X) && (cin >> Y)) {
        int ok = gcd(X, Y) == 1;
        cout << right << setw(10) << X << right << setw(10) << Y << setw(4) << " " << (ok ? "Good Choice" : "Bad Choice") << endl;
        cout << endl;
    }

    return 0;
}
