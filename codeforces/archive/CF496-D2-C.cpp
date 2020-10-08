#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
char arr[105][105];
bool isSmaller[105];
int ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= M; i++) {
        bool ok = true;
        for (int j = 1; j < N; j++) {
            if (!isSmaller[j] && arr[j][i] > arr[j + 1][i]) ok = false;
        }
        if (!ok) {
            ans++;
        } else {
            for (int j = 1; j < N; j++) {
                if (arr[j][i] < arr[j + 1][i]) isSmaller[j] = true;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
