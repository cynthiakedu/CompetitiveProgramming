#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
double arr[1000][2], adj[205][205];

double dist(double a, double b, double c, double d) {
    return sqrt((a - c) * (a - c) + (b - d) * (b - d));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (true) {
        ct++;
        cin >> N;
        if (N == 0) return 0;

        for (int i = 0; i < N; i++) cin >> arr[i][0] >> arr[i][1];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = dist(arr[i][0], arr[i][1], arr[j][0], arr[j][1]);
            }
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    adj[i][j] = min(adj[i][j], max(adj[i][k], adj[k][j]));
                }
            }
        }
        cout << "Scenario #" << ct << endl;
        cout << "Frog Distance = " << fixed << setprecision(3) << adj[0][1] << endl;
        cout << endl;
    }

    return 0;
}
