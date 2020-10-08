#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, a[200005], b[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> a[i];
    for (int i = 1; i <= N; i++) cin >> b[i];

    int idx = 1;
    for (int i = 1; i <= N; i++) {
        while (idx <= N && b[idx] != a[i]) idx++;
        if (idx == N + 1) {
            cout << N - (i - 1) << endl;
            return 0;
        }
    }
    cout << 0 << endl;

    return 0;
}
