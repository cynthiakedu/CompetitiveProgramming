#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> primes;
bool vis[1005];
vector<int> ans;

int p(int a, int b) {
    if (b == 0) return 1;
    int z = p(a, b / 2);
    return z * z * (b % 2 == 1 ? a : 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i <= 1000; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j <= 1000; j += i) {
            vis[j] = true;
        }
    }
    cin >> N;
    for (auto x : primes) {
        int ct = 0, N1 = N;
        while (N1 >= x) {
            ct++;
            N1 /= x;
            ans.push_back(p(x, ct));
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }

    return 0;
}
