#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 1e6;
ll N, M, arr[mxN + 5];
int arr2[mxN + 5];
ll l[mxN + 5];
int v[mxN + 5];
ll ans1 = 0, ans2 = -1;

ll gcd(ll x, ll y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

ll lcm(ll x, ll y) {
    return x * y / gcd(x, y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i <= M; i++) l[i] = 1;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] <= M) {
            arr2[arr[i]]++;
        }
    }

    for (ll i = 1; i <= M; i++) {
        for (ll j = i; j <= M; j += i) {
            v[j] += arr2[i];
            if (arr2[i]) l[j] = lcm(l[j], i);
        }
    }
    for (ll i = 1; i <= M; i++) {
        if (l[i] == i && v[i] > ans1) {
            ans1 = v[i];
            ans2 = i;
        }
    }
    if (ans2 == -1) {
        cout << 1 << " " << 0 << endl;
        cout << endl;
        return 0;
    }

    vector<int> ans3;
    for (int i = 1; i <= N; i++) {
        if (ans2 % arr[i] == 0) {
            ans3.push_back(i);
        }
    }
    cout << ans2 << " " << ans1 << endl;
    for (int i = 0; i < ans3.size(); i++) cout << ans3[i] << (i == ans3.size() - 1 ? "\n" : " ");

    return 0;
}
