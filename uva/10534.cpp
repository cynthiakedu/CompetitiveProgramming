#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int arr[10005];
int N;

void solve(int (&res)[10005]) {
    int temp[10005];
    for (int i = 0; i < 10005; i++) temp[i] = INT_MAX;
    for (int i = 1; i <= N; i++) {
        int x = arr[i];
        int pos = (int)(lower_bound(temp + 1, temp + N, x) - temp);
        temp[pos] = x;
        res[i] = pos;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> N) {
        for (int i = 1; i <= N; i++) cin >> arr[i];
        int res1[10005] = {};
        solve(res1);
        reverse(arr + 1, arr + N + 1);
        int res2[10005] = {};
        solve(res2);
        int mx = 0;
        reverse(arr + 1, arr + N + 1);

        for (int i = 1; i <= N; i++) {
            int a = res1[i], b = res2[N + 1 - i];
            int c = min(a, b);
            mx = max(mx, 2 * c - 1);
        }
        cout << mx << endl;
    }

    return 0;
}