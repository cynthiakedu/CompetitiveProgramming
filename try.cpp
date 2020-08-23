#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e8;

int N, M;
map<int, int> m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[2][2];
    arr[0][0] = 3;
    arr[0][1] = 4;
    arr[1][0] = 2;
    arr[1][5] = 5;
    sort(arr, arr + 2);
    cout << arr[0][0] << endl;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // int L;
    // cin >> L;
    // for (int l = 0; l < L; l++) {
    //     m.clear();
    //     cin >> N >> M;

    //     for (int i = 1, u, v; i <= M; i++) {
    //         cin >> u >> v;
    //         m[v]++;
    //     }
    //     int ans = 0;
    //     for (int i = 1; i <= N; i++) {
    //         if (m[i] == 0) ans++;
    //     }
    //     cout << ans << endl;
    // }
    cout << (1 << 30) << endl;

    return 0;
}
