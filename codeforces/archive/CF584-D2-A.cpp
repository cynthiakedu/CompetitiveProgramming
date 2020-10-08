#include <bits/stdc++.h>
using namespace std;
int N, T;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> T;
    int dig = T == 10 ? 2 : 1;
    if (T == 10 && N == 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << T;
    for (int i = 0; i < N - dig; i++) {
        cout << 0;
    }
    cout << endl;

    return 0;
}
