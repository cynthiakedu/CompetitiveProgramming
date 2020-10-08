#include <bits/stdc++.h>
using namespace std;
int N, x[5005], M, y[5005], K, z[5005], A, B;

double getR(double p1, double r1, double p2) {
    return sqrt((1.0 * p1 * B * pow(r1, 2)) / (1.0 * p1 * B + 1.0 * p2 * A));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> x[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> y[i];
    cin >> K;
    for (int i = 0; i < K; i++) cin >> z[i];
    cin >> A >> B;
    sort(x, x + N);

    double r2 = 0;
    double r1 = x[N - 1];
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < K; j++) {
            r2 = max(r2, getR(y[i], r1, z[j]));
        }
    }
    cout << setprecision(16) << r2 << endl;

    return 0;
}
