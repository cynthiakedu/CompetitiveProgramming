#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define PI 3.14159265
int N;
vector<double> A;
double chk(double a) {
    a += 720.0 * 4.0;
    while (a > 360.0) {
        a -= 360.0;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout << atan2(-1.0, -1.0) * 180.0 / PI << endl;
    cin >> N;
    for (int i = 0, x, y; i < N; i++) {
        cin >> x >> y;
        double a = atan2(1.0 * y, 1.0 * x) * 180.0 / PI;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    double ans = 360.0;
    for (int i = 0; i < A.size() - 1; i++) {
        ans = min(ans, 360.0 - chk(A[i == A.size() - 1 ? 0 : i + 1] - A[i]));
    }
    ans = min(ans, (A[A.size() - 1] - A[0]));
    cout << setprecision(25) << ans << endl;

    return 0;
}
