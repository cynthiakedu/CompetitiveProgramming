#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int ans[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    if (N % 4 == 0 || N % 4 == 1) {
        for (int i = 1; i <= N / 2; i += 2) {
            int a = i, b = i + 1;
            int c = N + 1 - a, d = N + 1 - b;
            ans[a] = b;
            ans[b] = c;
            ans[c] = d;
            ans[d] = a;
        }
        if (N % 2 == 1) {
            ans[(N + 1) / 2] = (N + 1) / 2;
        }
        for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");
    } else {
        cout << -1 << endl;
    }

    return 0;
}
