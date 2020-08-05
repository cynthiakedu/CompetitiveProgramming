#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, h[200005], mn = INT_MAX, mx = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        mn = min(x, mn);
        h[x]++;
        mx = max(mx, x);
    }
    vector<int> v = {};
    for (int i = mx; i > mn; i--) {
        h[i] += h[i + 1];
        v.push_back(h[i]);
    }

    int t = K, ct = 0;
    for (auto x : v) {
        if (t + x > K) {
            ct++;
            t = x;
        } else {
            t += x;
        }
    }
    cout << ct << endl;

    return 0;
}
