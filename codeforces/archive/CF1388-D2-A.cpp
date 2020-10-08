#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        if (N <= 30) {
            cout << "NO" << endl;
        }
        else if (N == 36 || N == 40 || N == 44) {
            cout << "YES" << endl;
            cout << 6 << " " << 10 << " " << 15 << " " << N - 31 << endl;
        }
        else {
            cout << "YES" << endl;
            cout << 6 << " " << 10 << " " << 14 << " " << N - 30 << endl;
        }
    }

    return 0;
}