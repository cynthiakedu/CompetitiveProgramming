#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

ll A, N, s;
ll arr[200005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> A;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        ll l = max((ll)1, A - (s - arr[i]));
        ll r = min(arr[i], A - (N - 1));
        ll ct = r - l + 1;
        ans.push_back(arr[i] - ct);
    }
    for (int i = 0; i < N; i++) cout << ans[i] << (i == N ? "\n" : " ");
    return 0;
}
