#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, x0, Y0, x1, Y11;
set<ii> S;
int vct = 0;
int same = 0;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> x0 >> Y0;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> Y11;
        if (x1 == x0) {
            if (Y11 == Y0)
                same += 1;
            else
                vct++;
        } else {
            int a = x1 - x0, b = Y11 - Y0;
            int g = gcd(abs(a), abs(b));
            a /= g, b /= g;
            if (a < 0 && b <= 0) {
                a *= -1, b *= -1;
            } else if (b < 0) {
                a *= -1;
                b *= -1;
            }
            S.insert(ii(a, b));
        }
    }
    cout << max((int)S.size() + (vct > 0), (int)(same > 0)) << endl;

    return 0;
}
