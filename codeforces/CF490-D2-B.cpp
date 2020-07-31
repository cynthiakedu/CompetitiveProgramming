#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N;
int ans[200005];
map<int, int> m, m2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        m[x] = y, m2[y] = x;
    }

    int t;
    for (auto x : m) {
        if (m2.count(x.first) == 0) t = x.first;
    }

    int lst = 0;
    for (int i = 2; i <= N; i += 2) {
        int nxt = m[lst];
        ans[i] = nxt;
        lst = nxt;
    }
    lst = t;
    ans[1] = t;
    for (int i = 3; i <= N; i += 2) {
        int nxt = m[lst];
        ans[i] = nxt;
        lst = nxt;
    }
    for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");

    return 0;
}
