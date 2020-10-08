#include <bits/stdc++.h>
using namespace std;
typedef pair<double, int> ii;
int N, T1, T2, K;
vector<ii> v;

double calc(double a, double b) {
    return (a * T1) * (100 - K) / 100 + b * T2;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> T1 >> T2 >> K;
    for (int i = 0; i < N; i++) {
        double a, b;
        cin >> a >> b;
        v.push_back(ii(-max(calc(a, b), calc(b, a)), i + 1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        cout << v[i].second << " " << fixed << setprecision(2) << -v[i].first << endl;
    }

    return 0;
}
