#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, N;
int arr[10005][3];

bool check(int x, int y) {
    for (int i = 1; i <= N; i++) {
        int r = arr[i][2], x1 = arr[i][0], y1 = arr[i][1];
        if ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y) <= r * r) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> c >> b >> d;
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

    int ans = 0;

    for (int i = a + 1; i < b; i++) {
        //(i, c), (i, d)
        if (!check(i, c)) ans++;
        if (!check(i, d)) ans++;
    }
    for (int i = c + 1; i < d; i++) {
        if (!check(a, i)) ans++;
        if (!check(b, i)) ans++;
    }
    if (!check(a, c)) ans++;
    if (!check(a, d)) ans++;
    if (!check(b, c)) ans++;
    if (!check(b, d)) ans++;
    cout << ans << endl;

    return 0;
}
