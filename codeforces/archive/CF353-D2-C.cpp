#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, arr[100005], cum[100005];
string m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = N - 1; i >= 0; i--) cin >> arr[i];
    for (int i = N - 1; i >= 0; i--) cum[i] = cum[i + 1] + arr[i];
    cin >> m;
    reverse(m.begin(), m.end());

    int s = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (m[i] == '0') continue;
        ans = max(ans, s + cum[i + 1]);
        s += arr[i];
    }
    ans = max(ans, s);
    cout << ans << endl;
    return 0;
}
