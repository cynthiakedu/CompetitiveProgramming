#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
typedef long double ld;
typedef complex<ld> P;
#define X real()
#define Y imag()
int N;
P arr[1005];
double ans = -1.0;

double cross(P a, P b) {
    return (conj(a) * b).Y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        arr[i] = {a, b};
    }

    for (int i = 0; i < N; i++) {
        P a = arr[i], b = arr[(i + 1) % N], c = arr[(i + 2) % N];
        P s1 = (a + b) * polar((ld)0.5, (ld)0.0);
        P s2 = (b + c) * polar((ld)0.5, (ld)0.0);
        double dist = abs(cross(s1 - a, s2 - a)) / abs(s1 - s2);
        if (ans == -1.0 || dist < ans) {
            ans = dist;
        }
    }
    cout << setprecision(16) << ans << endl;

    return 0;
}
