#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

map<int, int> m[4005];
int N, arr[4005];
int mx = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            int d = arr[i] - arr[j];
            m[i][d] = 1 + m[j][-d];
            mx = max(mx, m[i][d]);
        }
    }
    cout << mx + 1 << endl;
    return 0;
}
