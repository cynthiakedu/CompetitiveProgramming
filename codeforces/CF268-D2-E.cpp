#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
double prob[500005];
vector<pair<double, int>> v;
double ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    vector<pair<double, int>> v2;
    for (int i = 1; i <= N; i++) {
        double a, b;
        cin >> a >> b;
        ans += a;
        prob[i] = 1 - 1.0 * b / 100;
        if (b == 100) {
            v2.push_back({a, i});
        } else {
            v.push_back({a * (1 - prob[i]) / prob[i], i});
        }
    }
    sort(v.begin(), v.end());

    double cum = prob[v[0].second];
    for (int i = 1; i < v.size(); i++) {
        ans += cum * v[i].first * prob[v[i].second];
        cum += prob[v[i].second];
    }
    for (auto x : v2) {
        ans += cum * x.first;
    }
    cout << setprecision(16) << ans << endl;
    return 0;
}
