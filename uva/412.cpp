#include <bits/stdc++.h>
using namespace std;
int N;
int arr[100];

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N;
        if (N == 0) return 0;
        int amount = 0;
        for (int i = 1; i <= N; i++) cin >> arr[i];
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                if (gcd(arr[i], arr[j]) == 1) {
                    amount++;
                }
            }
        }
        int total = N * (N - 1) / 2;
        if (amount == 0) {
            cout << "No estimate for this data set." << endl;
        } else {
            cout << fixed << setprecision(6) << (sqrt(6.0 * total / amount)) << endl;
        }
    }

    return 0;
}
