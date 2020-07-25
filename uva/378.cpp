#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> ii;
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    cout << "INTERSECTING LINES OUTPUT" << endl;
    while (N--) {
        double a, b, c, d, e, f, g, h;
        cin >> a >> b >> c >> d >> e >> f >> g >> h;
        if (a == c) {
            if (e == g) {
                if (a == e) {
                    cout << "LINE" << endl;
                } else {
                    cout << "NONE" << endl;
                }
            } else {
                double m2 = (f - h) / (e - g);
                double b2 = f - e * m2;
                cout << "POINT " << fixed << setprecision(2) << a << " " << fixed << setprecision(2) << m2 * a + b2 << endl;
            }
        } else {
            double m1 = (b - d) / (a - c);
            double b1 = b - a * m1;
            double m2 = (f - h) / (e - g);
            double b2 = f - e * m2;
            if (m1 == m2) {
                if (b1 == b2) {
                    cout << "LINE" << endl;
                } else {
                    cout << "NONE" << endl;
                }
            } else {
                cout << "POINT ";
                double x = (b2 - b1) / (m1 - m2);
                double y = m1 * x + b1;
                cout << fixed << setprecision(2) << x << " ";
                cout << fixed << setprecision(2) << y << endl;
            }
        }
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
