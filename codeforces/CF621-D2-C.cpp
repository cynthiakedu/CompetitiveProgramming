#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, P, arr[100005][2];
double ans;

double prob(int l, int r) {
    int amt = r / P - (l - 1) / P;
    return 1.0 * amt / (r - l + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> P;
    for (int i = 1; i <= N; i++) cin >> arr[i][0] >> arr[i][1];

    for (int i = 1; i <= N; i++) {
        double p1 = prob(arr[i][0], arr[i][1]);
        double p2 = prob(arr[i == N ? 1 : i + 1][0], arr[i == N ? 1 : i + 1][1]);
        ans += (1.0 - (1.0 - p1) * (1 - 1.0 * p2)) * 2000;
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
