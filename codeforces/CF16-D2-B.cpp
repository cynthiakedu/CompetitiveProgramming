#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, M;
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0, x, y; i < M; i++) {
        cin >> x >> y;
        v.push_back(ii(y, x));
    }
    sort(v.rbegin(), v.rend());
    int ans = 0;
    for (int i = 0; i < M; i++) {
        int amt = min(v[i].second, N);
        N -= amt;
        ans += v[i].first * amt;
        if (N == 0) {
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
