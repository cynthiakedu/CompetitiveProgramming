#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c >> d;
    cout << (2 * (b + (c > d ? a : 0)) + (abs(d - c) - 1) * (a + 2 * b)) << endl;

    return 0;
}
