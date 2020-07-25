#include <bits/stdc++.h>
using namespace std;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N == 0 || N > 2) {
        cout << -1 << endl;
    } else if (N == 1) {
        cout << 1 << " " << 2 << " " << 3 << endl;
    } else {
        cout << 3 << " " << 4 << " " << 5 << endl;
    }

    return 0;
}
