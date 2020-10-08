#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N;
ll arr[mxN + 5], cum[mxN + 5];
ll s2, s1;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    sort(arr + 1, arr + N + 1);

    for (int i = 1; i <= N; i++) {
        cum[i] = cum[i - 1] + arr[i];
        // cout << "cum " << cum[i] << endl;
    }

    ll s2 = 0;
    for (int i = 1; i <= N; i++) {
        s2 += (cum[N] - cum[i]) - (N - i) * arr[i];
    }
    ll top = 2 * s2 + cum[N];
    ll bot = N;
    ll g = gcd(top, bot);
    cout << top / g << " " << bot / g << endl;

    return 0;
}
