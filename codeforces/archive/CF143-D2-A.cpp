#include <bits/stdc++.h>
using namespace std;
int r1, r2, c1, c2, d1, d2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r1 >> r2 >> c1 >> c2 >> d1 >> d2;
    int s = r1 + d1 - c2;
    if (s % 2 == 1 || s <= 0) {
        cout << -1 << endl;
        return 0;
    }
    int a = s / 2;
    int b = r1 - a, c = c1 - a, d = d1 - a;
    if (b <= 0 || b >= 10 || c <= 0 || c >= 10 || d <= 0 || d >= 10) {
        cout << -1 << endl;
        return 0;
    }
    if (a + b != r1 || c + d != r2 || b + c != d2) {
        cout << -1 << endl;
        return 0;
    }
    set<int> S;
    S.insert(a);
    S.insert(b);
    S.insert(c);
    S.insert(d);
    if (S.size() < 4) {
        cout << -1 << endl;
        return 0;
    }
    cout << a << " " << b << endl;
    cout << c << " " << d << endl;

    return 0;
}
