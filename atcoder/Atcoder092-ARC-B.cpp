#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, A[200005], B[200005];
int cumB[35];
int amt[35][200005];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;
        B[i] = x;
        for (int j = 29; j >= 0; j--) {
            cumB[j] ^= (x >> j) & 1;
            amt[j][i] = x % (1 << j);
        }
    }
    for (int i = 29; i >= 0; i--) {
        sort(amt[i] + 1, amt[i] + N + 1);
    }

    for (int i = 1; i <= N; i++) {
        int x = A[i];
        int temp = 0;
        for (int j = 29; j >= 0; j--) {
            int dig = (N & 1) & ((x >> j) & 1);
            int rem = x % (1 << j);
            dig ^= cumB[j];
            int pos = (int)(lower_bound(amt[j], amt[j] + N + 1, (1 << j) - rem) - amt[j]);
            int amt = N + 1 - pos;
            dig ^= (amt & 1);
            temp ^= (dig << j);
        }
        ans ^= temp;
    }
    cout << ans << endl;

    return 0;
}
