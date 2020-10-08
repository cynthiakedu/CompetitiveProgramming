#include <bits/stdc++.h>
using namespace std;
int N, K;
double arr[1000][2];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    double ans = 0;
    for (int i = 1; i < N; i++) {
        double d = pow((arr[i][0] - arr[i + 1][0]), 2) + pow((arr[i][1] - arr[i + 1][1]), 2);
        d = pow(d, 0.5);
        ans += d;
    }
    cout << setprecision(16) << K * (ans / 50) << endl;

    return 0;
}
