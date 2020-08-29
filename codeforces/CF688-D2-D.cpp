#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K, arr[1000005];
int g = 1;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1, x; i <= N; i++) {
        cin >> arr[i];
        x = arr[i];
        int g1 = gcd(x / gcd(g, x), K);
        g *= g1;
        K /= g1;
    }
    cout << (K == 1 ? "Yes" : "No") << endl;

    return 0;
}
