#include <bits/stdc++.h>
using namespace std;
int T, N, arr[100005], C;

bool can(int x) {
    int ct = 1;
    int idx = 1;
    for (int i = 2; i <= C; i++) {
        int nextIdx = (int)(lower_bound(arr + 1, arr + N + 1, arr[idx] + x) - arr);
        if (nextIdx == N + 1) return false;
        idx = nextIdx;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> C;
        for (int i = 1; i <= N; i++) {
            cin >> arr[i];
        }
        sort(arr + 1, arr + N + 1);
        int l = 1, r = 1000000000;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (can(m)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        cout << l << endl;
    }

    return 0;
}
