#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e8;

int N, M;
map<int, int> m;

int solve(int x) {
    x++;
    cout << x << endl;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    // for (int i = 0; i < 2000; i++) {
    //     s += 'q';
    // }
    // cout << sizeof(s) << endl;
    cout << "main " << solve(3) << endl;
    // cout << (-3) % 2 << endl;
    // int p = 5;
    // int inv[5] = {};
    // inv[1] = 1;
    // for (int i = 2; i < p; i++) {
    //     inv[i] = (p - (p / i) * inv[p % i] % p) % p;
    //     cout << "inv[i] " << i << " " << inv[i] << endl;
    // }

    // int arr[2][2];
    // arr[0][0] = 3;
    // arr[0][1] = 4;
    // arr[1][0] = 2;
    // arr[1][5] = 5;
    // sort(arr, arr + 2);
    // cout << arr[0][0] << endl;
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
    // cout << (1 << 30) << endl;

    return 0;
}
