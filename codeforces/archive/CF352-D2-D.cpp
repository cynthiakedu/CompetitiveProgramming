#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[3005];
int ct = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= N; i++) {
        int x = arr[i];
        for (int j = i + 1; j <= N; j++) {
            if (arr[i] > arr[j]) ct++;
        }
    }

    double ans = (ct / 2) * 4 + (ct % 2);
    cout << setprecision(16) << ans << endl;

    return 0;
}
