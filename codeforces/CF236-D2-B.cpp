#include <bits/stdc++.h>
using namespace std;
#define MOD 1073741824;
int A, B, C;
bool vis[1000005];
int d[1000005];
long long numDiv[1000005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2; i < 1000005; i++) {
        if (!vis[i]) {
            for (int j = i; j < 1000005; j += i) {
                vis[j] = true;
                d[j] = i;
            }
        }
    }
    for (int i = 1; i < 1000005; i++) {
        if (i == 1) {
            numDiv[i] = 1;
        } else {
            int ct = 0, x = i;
            while (x % d[i] == 0) {
                x /= d[i];
                ct++;
            }
            numDiv[i] = ((ct + 1) * numDiv[x]) % MOD;
        }
    }
    cin >> A >> B >> C;
    long long ans = 0;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= B; j++) {
            for (int k = 1; k <= C; k++) {
                int num = i * j * k;
                ans = (ans + numDiv[num]) % MOD;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
