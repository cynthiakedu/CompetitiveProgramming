#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
ll N, arr[100005], K;
ll v1[100005], v2[100005];
ll cum[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> arr[i];
    sort(arr, arr + N);

    int idx = 0, ct = 0;
    while (idx < N) {
        int j = idx;
        while (arr[j] == arr[idx]) j++;
        ct++;
        v1[ct] = arr[idx];
        v2[ct] = j - idx;
        idx = j;
    }
    for (int i = 1; i <= ct; i++) {
        cum[i] = cum[i - 1] + v2[i];
        // cout << "cum " << i << " " << cum[i] << endl;
    }

    ll div = (K + N - 1) / N;
    ll pos = (ll)(lower_bound(cum + 1, cum + ct + 1, div) - cum);
    ll prev = cum[pos - 1];
    // cout << "pos prev " << pos << " " << prev << endl;
    ll mod = K - (N * prev);
    ll x = (mod + v2[pos] - 1) / v2[pos];
    // cout << "mod x " << mod << " " << x << endl;

    cout << v1[pos] << " " << arr[x - 1] << endl;

    return 0;
}
