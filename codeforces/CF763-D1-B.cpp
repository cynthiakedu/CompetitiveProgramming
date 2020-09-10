#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int a, b, c, d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) {
        cin >> a >> b >> c >> d;
        if (a % 2 && b % 2) {
            cout << 1 << "\n";
        } else if (a % 2 && !(b % 2)) {
            cout << 2 << "\n";
        } else if (!(a % 2) && (b % 2)) {
            cout << 3 << "\n";
        } else {
            cout << 4 << "\n";
        }
    }

    return 0;
}
