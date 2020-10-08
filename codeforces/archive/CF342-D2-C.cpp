#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int R, H;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> H;
    if (H % R == 0) {
        cout << 1 + 2 * (H / R) << endl;
    } else {
        cout << 2 * ((H + R - 1) / R) << endl;
    }

    return 0;
}
