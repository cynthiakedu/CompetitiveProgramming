#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 5e5;
int N, K, D, arr[mxN + 5];

bool dp[mxN + 5];
bool tree[(1 << 20)];
int n = (1 << 19);

bool isTrue(int a, int b) {
    a += n;
    b += n;
    bool ret = false;
    while (a <= b) {
        if (a % 2 == 1) {
            ret = ret || tree[a];
            a++;
        }
        if (b % 2 == 0) {
            ret = ret || tree[b];
            b--;
        }

        a /= 2;
        b /= 2;
    }
    return ret;
}

void change(int k) {
    k += n;
    tree[k] = true;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] || tree[2 * k + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K >> D;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);
    change(N + 1);
    dp[N + 1] = true;
    for (int i = N; i >= 1; i--) {
        if (i + K - 1 > N) continue;
        int pos1 = i + K - 1;
        int pos2 = (int)(upper_bound(arr + i + 1, arr + N + 1, arr[i] + D) - arr);
        if (pos2 <= pos1) continue;
        if (isTrue(pos1 + 1, pos2)) {
            dp[i] = true;
            change(i);
        }
    }
    cout << (dp[1] ? "YES" : "NO") << endl;

    return 0;
}
