#include <bits/stdc++.h>
using namespace std;
char a, b, c, d, e, f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    a = s[0];
    b = s[2];
    if (s[1] == '>') swap(a, b);

    cin >> s;
    c = s[0];
    d = s[2];
    if (s[1] == '>') swap(c, d);

    cin >> s;
    e = s[0];
    f = s[2];
    if (s[1] == '>') swap(e, f);

    if (a == c) {
        cout << a << e << f << endl;
    } else if (a == d) {
        if (e == c) {
            cout << c << a << b << endl;
        } else {
            cout << "Impossible" << endl;
        }
    } else if (b == c) {
        if (a == e) {
            cout << a << b << d << endl;
        } else {
            cout << "Impossible" << endl;
        }
    } else {
        cout << e << f << b << endl;
    }

    return 0;
}
