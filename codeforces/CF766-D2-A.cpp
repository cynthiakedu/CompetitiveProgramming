#include <bits/stdc++.h>
using namespace std;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s1 >> s2;
    if (s1.compare(s2) == 0) {
        cout << -1 << endl;
    } else {
        cout << max(s1.size(), s2.size()) << endl;
    }

    return 0;
}
