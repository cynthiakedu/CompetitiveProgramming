#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int arr[300005];
int memo[20][300005];
vector<int> v;
int vis[1000005];

int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

void check(int x) {
    int k = floor(log2(x));

    v.clear();
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= x; i++) {
        vis[arr[i]]++;
    }
    for (int i = 1; i <= N + 1 - x; i++) {
        int j = i + x;
        int a = memo[k][i], b = memo[k][j - (1 << k)];
        int g = gcd(a, b);
        if (vis[g]) v.push_back(i);

        vis[arr[i]]--;
        vis[arr[i + x]]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 0; i <= floor(log2(N)); i++) {
        for (int j = 1; j <= N + 1 - i; j++) {
            int k = i - 1;
            if (i == 0) {
                memo[i][j] = arr[j];
            } else {
                int b = j + (1 << i) - 1;
                memo[i][j] = gcd(memo[k][j], memo[k][b + 1 - (1 << k)]);
            }
        }
    }

    int l = 1, r = N;
    while (l < r) {
        int m = (l + r + 1) / 2;
        check(m);
        if (v.size() > 0) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    check(l);
    cout << v.size() << " " << l - 1 << "\n";
    for (int i = 0; i < v.size(); i++) cout << v[i] << (i == v.size() - 1 ? "\n" : " ");

    return 0;
}
