#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 100005
bool debug = false;

ll N, K, w[MXN + 5];
ll ff[MXN][34], m[MXN][34], s[MXN][34];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    for (int i = 0; i < N; i++) cin >> ff[i][0];
    for (int i = 0; i < N; i++) {
        cin >> w[i];
        m[i][0] = s[i][0] = w[i];
    }

    for (int i = 1; i < 34; i++) {
        for (int j = 0; j < N; j++) {
            ff[j][i] = ff[ff[j][i - 1]][i - 1];
            m[j][i] = min(m[j][i - 1], m[ff[j][i - 1]][i - 1]);
            s[j][i] = s[j][i - 1] + s[ff[j][i - 1]][i - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        int curr = i;
        ll s1 = 0, m1 = LLONG_MAX;
        for (int j = 0; j < 34; j++) {
            if (K & (1LL << j)) {
                s1 += s[curr][j];
                m1 = min(m1, m[curr][j]);
                curr = ff[curr][j];
            }
        }
        cout << s1 << " " << m1 << "\n";
    }
    return 0;
}
