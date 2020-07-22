#include <bits/stdc++.h>
using namespace std;
int T, A;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A;
        cout << (360 % (180 - A) == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}
