#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
int N, F, arr[100005][2];
bool arr2[100005];
vector<ii> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> F;
    for (int i = 1, a, b; i <= N; i++) {
        cin >> a >> b;
        arr[i][0] = a;
        arr[i][1] = b;
        v.push_back(ii(min(2 * a, b) - min(a, b), i));
    }
    sort(v.rbegin(), v.rend());
    for (int i = 0; i < F; i++) {
        arr2[v[i].second] = true;
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        int a = arr[i][0], b = arr[i][1];
        if (arr2[i]) {
            ans += min(2 * a, b);
        } else {
            ans += min(a, b);
        }
    }
    cout << ans << endl;

    return 0;
}
