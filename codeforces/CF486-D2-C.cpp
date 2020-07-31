#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, P;
char arr[100005];
int l = -1, r = -1;
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P;
    for (int i = 0; i < N; i++) cin >> arr[i];
    P -= 1;
    if (P >= N / 2) P = N - 1 - P;

    for (int i = 0; i < N / 2; i++) {
        if (arr[i] != arr[N - 1 - i]) {
            l = i;
            break;
        }
    }
    for (int i = N / 2 - 1; i >= 0; i--) {
        if (arr[i] != arr[N - 1 - i]) {
            r = i;
            break;
        }
    }
    if (l == -1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = l; i <= r; i++) {
        int num = arr[N - 1 - i] - arr[i];
        num = (num + 26) % 26;
        num = min(num, 26 - num);
        ans += num;
    }

    if (P <= l) {
        ans += r - P;
    } else if (P >= r) {
        ans += P - l;
    } else {
        int a = P - l, b = r - P;
        ans += min(a - 1, b - 1) + r - l + 1;
    }
    cout << ans << endl;

    return 0;
}
