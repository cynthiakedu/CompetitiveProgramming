#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, R;
long double arr[25];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int C = 0;
    while (true) {
        cin >> N >> R;
        if (N == 0 && R == 0) return 0;
        C++;
        cout << "Case " << C << ":" << endl;
        for (int i = 0; i < N; i++) cin >> arr[i];
        long double P[25] = {}, s = 0;
        for (int i = 0; i < (1 << N); i++) {
            long double p = 1;
            int ct = 0;
            for (int j = 0; j < N; j++) {
                if ((i & (1 << j))) {
                    p *= arr[j];
                    ct++;
                } else {
                    p *= 1 - arr[j];
                }
            }
            if (ct == R) {
                s += p;
                for (int j = 0; j < N; j++) {
                    if ((i & (1 << j))) {
                        P[j] += p;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            cout << fixed << setprecision(6) << P[i] / s << endl;
        }
    }

    return 0;
}
