#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
typedef long double ld;
typedef complex<ld> P;
#define X real()
#define Y imag()
vector<P> v;
long double getArea(vector<P> v) {
    long double area = 0;
    for (int i = 0; i < v.size(); i++) {
        P a = v[i], b = v[(i + 1) % ((int)v.size())];
        area += (conj(a) * b).Y;
    }
    area = abs(area) / 2.0;
    return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;
    while (true) {
        v.clear();
        ct++;
        bool ok = false;
        for (int i = 0; i < 4; i++) {
            long double a, b;
            cin >> a >> b;
            if (a != 0 || b != 0) ok = true;
            v.push_back(P{a, b});
        }
        if (!ok) return 0;
        long double wholeArea = getArea(v);
        vector<long double> areas;
        for (int i = 0; i < 4; i++) {
            vector<P> v1;
            for (int j = 0; j < 4; j++) {
                if (j != i) {
                    v1.push_back(v[j]);
                }
            }
            long double temp = getArea(v1);
            areas.push_back(temp);
            areas.push_back(temp / 2);
            areas.push_back(temp / 4);
        }
        vector<P> v1 = {v[0], (v[0] + v[1]) / polar((ld)2.0, (ld)0.0), (v[2] + v[3]) / polar((ld)2.0, (ld)0.0), v[3]};
        vector<P> v2 = {v[0], v[1], (v[1] + v[2]) / polar((ld)2.0, (ld)0.0), (v[3] + v[0]) / polar((ld)2.0, (ld)0.0)};
        areas.push_back(getArea(v1));
        areas.push_back(getArea(v2));

        long double ans = wholeArea;
        long double a = 0, b = wholeArea;
        for (auto x : areas) {
            long double y = wholeArea - x;
            if (fabs(y - x) < ans) {
                ans = fabs(y - x);
                a = min(x, y);
                b = max(x, y);
            }
        }
        cout << "Cake " << ct << ": ";
        cout << fixed << setprecision(3) << a << " " << fixed << setprecision(3) << b << endl;
    }

    return 0;
}
