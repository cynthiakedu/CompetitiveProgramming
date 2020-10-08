#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define T (1 << 20)

int N, arr[1000005], arr2[1000005];
pair<int, int> arr3[1000005];

int tree[2 * T];

int query(int a, int b, int l = 0, int r = T - 1, int p = 1) {
    if (a <= l && r <= b) return tree[p];

    int m = (l + r) / 2;
    if (b <= m) return query(a, b, l, m, 2 * p);
    if (a > m) return query(a, b, m + 1, r, 2 * p + 1);
    return query(a, b, l, m, 2 * p) + query(a, b, m + 1, r, 2 * p + 1);
}

void update(int k, int x) {
    k += T;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2) {
        tree[k] = tree[2 * k] + tree[2 * k + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        arr3[i] = {arr[i], i};
    }
    sort(arr3 + 1, arr3 + N + 1);

    for (int i = 1; i <= N; i++) {
        arr2[arr3[i].second] = i;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        int pos = arr2[i];
        int x = query(pos, N);
        int y = (pos - 1) - ((i - 1) - x);
        ans += (ll)x * y;
        update(arr2[i], 1);
    }
    cout << ans << endl;

    return 0;
}
