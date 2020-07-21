#include <bits/stdc++.h>
using namespace std;
int N, arr[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int t = max(arr[N] - arr[i], arr[i] - arr[1]);
        int s = min(i == N ? INT_MAX : arr[i + 1] - arr[i], i == 1 ? INT_MAX : arr[i] - arr[i - 1]);
        cout << s << " " << t << endl;
    }

    return 0;
}
