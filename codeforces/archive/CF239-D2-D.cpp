#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N;
ll H, arr[mxN + 5];
ll mn = LLONG_MAX, mnIdx = -1;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] < mn) {
            mn = arr[i];
            mnIdx = i;
        }
    }
    sort(arr + 1, arr + N + 1);
    if (N == 2) {
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    vector<ll> v1 = {arr[N] + arr[1] + H, arr[N - 1] + arr[N], arr[2] + arr[3], arr[1] + arr[2] + H};
    vector<ll> v2 = {arr[N] + arr[N - 1], arr[1] + arr[2]};
    ll ans1 = *max_element(v1.begin(), v1.end()) - *min_element(v1.begin(), v1.end());
    ll ans2 = v2[0] - v2[1];
    if (ans1 < ans2) {
        cout << ans1 << endl;
        for (int i = 1; i <= N; i++) cout << (i == mnIdx ? 1 : 2) << (i == N ? "\n" : " ");
    } else {
        cout << ans2 << endl;
        for (int i = 1; i <= N; i++) cout << 2 << (i == N ? "\n" : " ");
    }
    return 0;
}
