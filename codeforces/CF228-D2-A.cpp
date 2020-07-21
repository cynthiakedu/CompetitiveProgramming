#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d;
    s.insert(a);
    s.insert(b);
    s.insert(c);
    s.insert(d);

    cout << max(0, 4 - (int)s.size()) << endl;

    return 0;
}
