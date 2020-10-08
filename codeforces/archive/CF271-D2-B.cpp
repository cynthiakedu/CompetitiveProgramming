#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

vector<int> primes;
bool vis[100050];
int N, M;
int arr[505][505];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i < 100050; i++) {
        if (vis[i]) continue;
        primes.push_back(i);
        for (int j = i; j < 100050; j += i) {
            vis[j] = true;
        }
    }
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < N; i++) {
        int res = 0;
        for (int j = 0; j < M; j++) {
            int pos = (int)(lower_bound(primes.begin(), primes.end(), arr[i][j]) - primes.begin());
            res += primes[pos] - arr[i][j];
        }
        ans = min(ans, res);
    }
    for (int j = 0; j < M; j++) {
        int res = 0;
        for (int i = 0; i < N; i++) {
            int pos = (int)(lower_bound(primes.begin(), primes.end(), arr[i][j]) - primes.begin());
            res += primes[pos] - arr[i][j];
        }
        ans = min(ans, res);
    }
    cout << ans << endl;

    return 0;
}
