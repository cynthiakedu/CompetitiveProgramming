#include <bits/stdc++.h>
using namespace std;
int N, p = 0, n = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        if (x >= 0 && x % 2 == 1) p++;
        if (x < 0 && (-x) % 2 == 1) n++;
        int amt = x >= 0 ? p : n;
        int x1 = abs(x);
        if (x1 % 2 == 1 && amt % 2 == 1)
            x1 = (x1 + 1) / 2;
        else
            x1 = x1 / 2;
        cout << (x1 * (x >= 0 ? 1 : -1)) << endl;
    }

    return 0;
}
