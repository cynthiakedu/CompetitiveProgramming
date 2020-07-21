#include <bits/stdc++.h>
using namespace std;
int N, mn = INT_MAX, mx = INT_MIN, arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
    }
    int ct = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] != mn && arr[i] != mx) {
            ct++;
        }
    }
    cout << ct << endl;

    return 0;
}
