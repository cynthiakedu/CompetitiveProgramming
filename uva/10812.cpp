#include <bits/stdc++.h>
using namespace std;
int N, a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a < b || (a % 2 != b % 2)) {
            cout << "impossible" << endl;
        } else {
            cout << (a + b) / 2 << " " << (a - b) / 2 << endl;
        }
    }

    return 0;
}
