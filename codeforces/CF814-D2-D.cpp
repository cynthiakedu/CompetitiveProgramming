#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
const double PI = 3.14159265359;
double arr[1005][3];

bool isInside(int i, int j) {
    if (arr[i][2] > arr[j][2]) return false;
    double d = (arr[i][0] - arr[j][0]) * (arr[i][0] - arr[j][0]);
    d += (arr[i][1] - arr[j][1]) * (arr[i][1] - arr[j][1]);
    double d2 = arr[j][2] * arr[j][2];
    return d <= d2;
}

double getArea(int i) {
    return arr[i][2] * arr[i][2] * PI;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    double ans = 0;
    for (int i = 0; i < N; i++) {
        int ct = 0;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (isInside(i, j)) ct++;
        }
        double sign = ct <= 1 ? 1 : (ct % 2 == 0) ? -1 : 1;
        ans += sign * getArea(i);
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
