#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll K;
ll arr[50005], cum[500005];

bool check(ll sum) {
    ll ct = 0;
    for (int i = 1; i <= N; i++) {
        ll need = cum[i - 1] + sum;
        int pos = (int)(upper_bound(cum, cum + N + 1, need) - cum);
        ct += pos - i;
    }
    return ct >= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        cum[i] = arr[i] + cum[i - 1];
    }

    ll l = 1, r = 100000000000005;
    while (l < r) {
        ll m = (l + r) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}
