#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M;
ll arr[5005], bad[5005];
ll sub = 0, add = 0;

ll pow(ll a, ll b) {
    if (b == 0) return 1;
    ll z = pow(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= M; i++) {
        cin >> bad[i];
        int mn = INT_MAX, temp = 0;
        int x = arr[i];
        for (int j = 1; j <= N; j++) {
            while (x % bad[i] == 0) {
                x /= bad[i];
                temp++;
            }
            mn = min(temp, mn);
            sub += temp - mn;
            arr[i] /= pow(bad[i], mn);
        }
    }

    return 0;
}
