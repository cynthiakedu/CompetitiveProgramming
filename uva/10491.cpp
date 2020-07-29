#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int co, ca, nshow;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while ((cin >> co) && (cin >> ca) && (cin >> nshow)) {
        double a = (1.0 * co / (co + ca)) * (1.0 * ca / (co + ca - 1 - nshow));
        double b = (1.0 * ca / (co + ca)) * (1.0 * (ca - 1) / (co + ca - 1 - nshow));
        cout << fixed << setprecision(5) << a + b << endl;
    }

    return 0;
}
