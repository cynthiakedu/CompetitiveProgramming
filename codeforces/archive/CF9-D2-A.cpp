#include <bits/stdc++.h>
using namespace std;
int a, b;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    int amt = 7 - max(a, b);
    int g = gcd(amt, 6);
    cout << amt / g << "/" << 6 / g << endl;

    return 0;
}
