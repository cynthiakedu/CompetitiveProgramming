#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define EPS 10e-9
#define PI 3.14159265

int N;
double a1, b1, a2, b2, a3, b3, a4, b4;

double dist(double ax, double ay, double bx, double by) {
    return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}

double ang(double ax, double ay, double bx, double by, double cx, double cy) {
    double m = dist(ax, ay, bx, by);
    double n = dist(bx, by, cx, cy);
    double t = dist(ax, ay, cx, cy);
    double c = (m * m + n * n - t * t) / (2 * m * n);
    // cout << "m n t " << m << " " << n << " " << t << endl;
    return acos(c);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a1 >> b1 >> a2 >> b2;
        cin >> a3 >> b3 >> a4 >> b4;
        double angle1 = ang(a2, b2, a1, b1, a3, b3) * 180 / PI;
        double angle2 = ang(a4, b4, a3, b3, a1, b1) * 180 / PI;
        if (angle2 > angle1) {
            if (fabs(angle2 - angle1) < EPS) {
                cout << 0 << endl;
            } else {
                cout << "Hero" << endl;
            }
        } else {
            if (fabs(angle2 - angle1) < EPS) {
                cout << 0 << endl;
            } else {
                cout << "Heroine" << endl;
            }
        }
    }

    return 0;
}

// 1
// 9 3 6 0 4 4 6 6
