#include <bits/stdc++.h>
using namespace std;
int N, arr[20], L, R, X, cum[20];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> L >> R >> X;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        cum[i] = cum[i - 1] + arr[i];
    }
    int ans = 0;
    for (int i = 1; i < N; i++) {
        int l = i + 1;
    }

    return 0;
}
