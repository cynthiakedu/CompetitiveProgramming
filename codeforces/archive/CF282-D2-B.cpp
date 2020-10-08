#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
int ans[1000005];
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ct = 0;

    cin >> N;
    for (int i = 1, a, b; i <= N; i++) {
        cin >> a >> b;
        v.push_back({a, i});
        ct += a;
    }
    sort(v.begin(), v.end());
    int s = 0;
    bool ok = false;
    int s1 = N * 1000 - ct;
    if (abs(s - s1) <= 500) {
        ok = true;
    }
    if (!ok) {
        for (int i = 0; i < N; i++) {
            s += v[i].first;
            ans[v[i].second] = 1;
            int s1 = (N - (i + 1)) * 1000 - (ct - s);
            if (abs(s - s1) <= 500) {
                ok = true;
                break;
            }
        }
    }

    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 1; i <= N; i++) {
        cout << (ans[i] ? "A" : "G");
    }
    cout << endl;

    return 0;
}
