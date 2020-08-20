#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
#define mx 1000000000
int N, M;
int cum[5005];
int guess[5005];
int guess2[5005];
vector<int> queries[5005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 5005; i++) guess[i] = mx;
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int type, l, r, x;
        cin >> type >> l >> r >> x;
        if (type == 1) {
            for (int j = l; j <= r; j++) cum[j] += x;
        } else {
            for (int j = l; j <= r; j++) guess[j] = min(guess[j], x - cum[j]);
        }
        queries[i] = {type, l, r, x};
    }
    for (int i = 1; i <= N; i++) {
        guess2[i] = guess[i];
    }
    for (int i = 1; i <= M; i++) {
        if (queries[i][0] == 1) {
            for (int j = queries[i][1]; j <= queries[i][2]; j++) guess2[j] += queries[i][3];
        } else {
            int tmpMax = INT_MIN;
            for (int j = queries[i][1]; j <= queries[i][2]; j++) {
                tmpMax = max(tmpMax, guess2[j]);
            }
            if (tmpMax != queries[i][3]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= N; i++) cout << guess[i] << (i == N ? "\n" : " ");

    return 0;
}
