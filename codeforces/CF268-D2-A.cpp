#include <bits/stdc++.h>
using namespace std;

int N;
int arr[35][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (arr[i][0] == arr[j][1]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
