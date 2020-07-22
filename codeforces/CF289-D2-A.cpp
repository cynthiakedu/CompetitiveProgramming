#include <bits/stdc++.h>
using namespace std;
int s = 0;
int N, K;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    while (N--) {
        int x, y;
        cin >> x >> y;
        s += (y - x + 1);
    }
    s %= K;
    if (s == 0) {
        cout << 0 << endl;
    } else {
        cout << K - s << endl;
    }

    return 0;
}
