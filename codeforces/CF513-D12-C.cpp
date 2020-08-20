#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
double arr[10][2];

double ans = 0;

double getProb(int idx, double down, double up) {
    double total = arr[idx][1] - arr[idx][0] + 1;
    double r = min(up, arr[idx][1]);
    double l = max(down, arr[idx][0]);
    double ct = max((double)0, r - l + 1);
    // if (up == 1.0) {
    //     cout << "up 1.0 " << ct << " " << total << " " << ct / total << endl;
    // }
    return ct / total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    double ans = 0;
    for (double i = 1; i <= 10000; i++) {
        double temp = 0;
        for (int j = 1; j <= N; j++) {
            double p1 = 1 - getProb(j, 0, i);
            double p2 = 1.0, p3 = 1.0;
            for (int k = 1; k <= N; k++) {
                if (k == j) continue;
                p2 *= getProb(k, 0, i);
                p3 *= getProb(k, 0, i - 1);
            }
            // cout << "p1 p2 p3 " << j << " " << p1 << " " << p2 << " " << p3 << endl;
            temp += p1 * (p2 - p3);
        }
        for (int j = 0; j < (1 << (N)); j++) {
            int ct = 0;
            for (int k = 1; k <= N; k++) {
                if (j & (1 << (k - 1))) {
                    ct++;
                }
            }
            if (ct >= 2) {
                double prob = 1.0;
                for (int k = 1; k <= N; k++) {
                    if (j & (1 << (k - 1))) {
                        // cout << "first " << 1 - getProb(k, i, i) << endl;
                        // cout << "prob " << prob << endl;
                        prob *= getProb(k, i, i);
                    } else {
                        // cout << "first " << getProb(k, 0, i - 1) << endl;
                        // cout << "prob " << endl;
                        prob *= getProb(k, 0, i - 1);
                    }
                }
                temp += prob;
            }
        }
        // if (temp > 0) {
        //     cout << "prob " << i << " " << temp << endl;
        // }
        ans += 1.0 * i * temp;
    }
    cout << setprecision(16) << ans << endl;
    return 0;
}
