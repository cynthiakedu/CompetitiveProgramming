#include <bits/stdc++.h>
using namespace std;
long long L, R;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> L >> R;
    cout << "YES" << endl;
    for (long long i = L; i < R; i += 2) {
        cout << i << " " << i + 1 << endl;
    }

    return 0;
}
