#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N % 2 == 0) {
        cout << -1 << endl;
    } else {
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cout << i << (i == N - 1 ? "\n" : " ");
            }
        }
        for (int i = 0; i < N; i++) {
            cout << (2 * i) % N << (i == N - 1 ? "\n" : " ");
        }
    }

    return 0;
}
