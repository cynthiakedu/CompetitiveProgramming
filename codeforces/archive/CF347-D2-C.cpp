#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, arr[105], mx = 0, g = 0;

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        g = gcd(g, arr[i]);
        mx = max(mx, arr[i]);
    }
    int left = (mx) / g - N;
    cout << (left % 2 == 1 ? "Alice" : "Bob") << endl;

    return 0;
}
