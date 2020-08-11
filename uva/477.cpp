#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int type[15];
double arr[15][4];

bool isInside(double x, double y, int idx) {
    if (type[idx] == 0) {  //rectangle
        if (x <= arr[idx][0] || x >= arr[idx][2]) {
            return false;
        }
        if (y <= arr[idx][3] || y >= arr[idx][1]) {
            return false;
        }
    } else {
        double d = (x - arr[idx][0]) * (x - arr[idx][0]) + (y - arr[idx][1]) * (y - arr[idx][1]);
        if (d >= arr[idx][2] * arr[idx][2]) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char t;
    int N = 0;
    while (true) {
        // cout << "USE N  " << N << endl;
        cin >> t;
        // cout << "type " << t << endl;
        if (t == '*') break;

        if (t == 'c') {
            type[N] = 1;
            cin >> arr[N][0] >> arr[N][1] >> arr[N][2];
        } else {
            type[N] = 0;
            cin >> arr[N][0] >> arr[N][1] >> arr[N][2] >> arr[N][3];
        }
        N++;
    }
    double a, b;
    int ct = 0;
    while ((cin >> a) && (cin >> b)) {
        if ((a == 9999.9) && (b = 9999.9)) return 0;
        ct++;
        int amt = 0;
        for (int i = 0; i < N; i++) {
            if (isInside(a, b, i)) {
                amt++;
                cout << "Point " << ct << " is contained in figure " << i + 1 << endl;
            }
        }
        if (!amt) {
            cout << "Point " << ct << " is not contained in any figure" << endl;
        }
    }

    return 0;
}
