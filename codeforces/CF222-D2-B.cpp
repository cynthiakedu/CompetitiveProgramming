#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K;
int arr[1005][1005];
int rowm[1005], colm[1005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) rowm[i] = i;
    for (int j = 1; j <= M; j++) colm[j] = j;
    for (int i = 0; i < K; i++) {
        char s;
        int x, y;
        cin >> s >> x >> y;
        if (s == 'c') {
            swap(colm[x], colm[y]);
        } else if (s == 'r') {
            swap(rowm[x], rowm[y]);
        } else {
            cout << arr[rowm[x]][colm[y]] << "\n";
        }
    }

    return 0;
}
