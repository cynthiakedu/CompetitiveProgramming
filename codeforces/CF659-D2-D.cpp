#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[1005][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i <= N; i++) cin >> arr[i][0] >> arr[i][1];
    int ct = 0;
    for (int i = 0; i < N; i++) {
        int i1 = i, i2 = (i + 1) % N, i3 = (i + 2) % N;
        int dx1 = arr[i2][0] - arr[i1][0], dy1 = arr[i2][1] - arr[i1][1];
        int dx2 = arr[i3][0] - arr[i2][0], dy2 = arr[i3][1] - arr[i2][1];
        if (dx1 > 0 && dy2 > 0) ct++;
        if (dy1 > 0 && dx2 < 0) ct++;
        if (dy1 < 0 && dx2 > 0) ct++;
        if (dx1 < 0 && dy2 < 0) ct++;
    }
    cout << ct << endl;

    return 0;
}
