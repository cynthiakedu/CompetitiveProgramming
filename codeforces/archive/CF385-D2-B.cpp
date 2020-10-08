#include <bits/stdc++.h>
using namespace std;
int N;
string s;
int arr[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    N = s.size();
    for (int i = 0; i <= N; i++) arr[i] = -1;
    for (int i = 0; i <= N - 4; i++) {
        if (s.substr(i, 4) == "bear") {
            arr[i] = i + 3;
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (arr[i] == -1) arr[i] = arr[i + 1];
    }
    int ans = 0;
    for (int i = 0; i <= N - 4; i++) {
        if (arr[i] != -1) {
            ans += N - arr[i];
        }
    }
    cout << ans << endl;

    return 0;
}
