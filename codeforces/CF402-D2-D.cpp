#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, arr[5005];
int bad[5005];
int ct[5005], mn[5005];
ll sub = 0, add = 0;
set<int> primes;
bool vis[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 1000005; i++) {
        if (vis[i]) continue;
        primes.insert(i);
        for (int j = i; j < 1000005; j += i) {
            vis[j] = true;
        }
    }

    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> arr[i];
    for (int i = 1; i <= M; i++) {
        cin >> bad[i];
        if (primes.count(bad[i])) {
            primes.erase(bad[i]);
        }
    }
    mn[0] = INT_MAX;
    for (int i = 1; i <= M; i++) {
        int p = bad[i];
        for (int j = 1; j <= N; j++) {
            ct[j] = 0;
            while (arr[j] % p == 0) {
                ct[j]++;
                arr[j] /= p;
            }
        }
        for (int j = 1; j <= N; j++) {
            mn[j] = min(mn[j - 1], ct[j]);
            ct[j] -= mn[j];
        }
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            ans += ct[j];
        }
        sub += ans;
    }
    for (int j = 1; j <= N; j++) {
        }

    return 0;
}
