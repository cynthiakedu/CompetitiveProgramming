#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
double A;

double calc(int n) {
    double x = (1.0 * (n - 2) * A - 1.0 * (n - 2) * (n - 1)) / (n - 1);
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> N) {
        cin >> A;
        double mx = 0;
        for (int n = 1; n <= N; n++) {
            double x = calc(n);
            mx = max(x, mx);
        }
        cout << fixed << setprecision(2) << ((N - 1) * mx + (N - 2) * (N - 1) - (N - 2) * A) << endl;
    }

    return 0;
}
