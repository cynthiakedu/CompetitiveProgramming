#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, K, S;
ll arr[30], fact[20], curr, ans;

void solve(int idx, int num) {
    if (curr > S) return;
    if (idx == N + 1) {
        if (curr == S) ans++;
        return;
    }
    solve(idx + 1, num);

    curr += arr[idx];
    solve(idx + 1, num);
    curr -= arr[idx];

    if (num == K) return;
    if (arr[idx] >= 19 || arr[idx] == 1) return;

    curr += fact[arr[idx]];
    solve(idx + 1, num + 1);
    curr -= fact[arr[idx]];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fact[0] = 1;
    for (ll i = 1; i <= 19; i++) fact[i] = fact[i - 1] * i;

    cin >> N >> K >> S;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    solve(1, 0);
    cout << ans << endl;
    return 0;
}
