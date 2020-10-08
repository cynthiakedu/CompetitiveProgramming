#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N;
int ans[2][100005];
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N / 2; i++) {
        ans[0][i] = 1;
        ans[1][i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, -i});
        v.push_back({b, i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < N; i++) {
        ii p = v[i];
        if (p.second < 0) {
            ans[0][-p.second] = 1;
        } else {
            ans[1][p.second] = 1;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= N; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }

    return 0;
}
