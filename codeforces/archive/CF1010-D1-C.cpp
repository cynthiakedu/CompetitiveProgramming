#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, K;
int g;
int gcd(int x, int y) {
    if (x == 0) return y;
    return gcd(y % x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    g = K;
    for (int i = 0, x; i < N; i++) {
        cin >> x;
        g = gcd(g, x);
    }
    vector<int> ans;
    for (int i = 0; i < K; i++) {
        if (i % g == 0) ans.push_back(i);
    }
    cout << (int)ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) cout << ans[i] << (i == ((int)ans.size() - 1) ? "\n" : " ");

    return 0;
}
