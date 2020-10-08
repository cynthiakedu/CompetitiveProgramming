#include <bits/stdc++.h>
using namespace std;
int K, N;

bool isGood(int x) {
    int arr[10] = {};
    while (x > 0) {
        arr[x % 10] = 1;
        x /= 10;
    }
    for (int i = 0; i <= K; i++) {
        if (!arr[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (isGood(x)) ans++;
    }
    cout << ans << endl;
    return 0;
}
