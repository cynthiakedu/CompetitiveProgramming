#include <bits/stdc++.h>
using namespace std;
int N, M;

bool isPrime[55], vis[55];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= 50; i++) {
        if (!vis[i]) {
            isPrime[i] = true;
            for (int j = i; j <= 50; j += i) {
                vis[j] = true;
            }
        }
    }

    cin >> N >> M;
    if (!isPrime[M]) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = N + 1; i < M; i++) {
        if (isPrime[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}
