#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
ll arr[100005];
ll s = 0;

bool can(ll x) {
    ll ct = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] > x) return false;
        ct += x - arr[i];
    }
    if (ct >= x) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        s += arr[i];
    }

    ll l = 1, r = s + 1;

    while (l < r) {
        ll m = (l + r) / 2;
        if (can(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;

    return 0;
}
