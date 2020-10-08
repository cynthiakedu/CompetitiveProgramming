#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, arr[100005];
ll ans = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    ll i = 0;
    while (i < N) {
        ll j = i;
        while (j < N && arr[i] == arr[j]) {
            j++;
        }
        ll n = j - i;
        ans += n * (n + 1) / 2;
        i = j;
    }
    cout << ans << endl;

    return 0;
}
