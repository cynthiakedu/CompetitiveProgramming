#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, a[1000005], b[1000005];
int arr[35];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < M; i++) {
        cin >> b[i];
        arr[b[i]]++;
    }

    sort(a, a + N);

    int ans = 0;
    for (int i = 0; i < 32; i++) {
        int ct = arr[i];
        int odd = 0;
        for (int j = 0; j < N; j++) {
            if (a[j] % 2 == 1) {
                a[j]--;
                odd++;
            }
        }
        ans += min(ct, odd);
        ct -= min(ct, odd);
        if (ct == 0) {
            for (int j = 0; j < N; j++) a[j] /= 2;
            continue;
        }
        for (int j = 0; j < N; j++) {
            int add = min(ct, a[j]);
            ans += add;
            ct -= add;
            a[j] -= add;
            if (ct == 0) break;
        }
        for (int j = 0; j < N; j++) a[j] /= 2;
    }
    cout << ans << endl;

    return 0;
}
