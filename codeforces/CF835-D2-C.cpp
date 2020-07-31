#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, Q, C;
int B[100005];
map<ii, vector<int>> stars;
int amt[15][105][105];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> Q >> C;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y >> B[i];
        stars[ii(x, y)].push_back(i);
    }

    for (int c = 0; c <= C; c++) {
        for (int i = 1; i <= 100; i++) {
            for (int j = 1; j <= 100; j++) {
                int ne = 0;
                for (auto x : stars[ii(i, j)]) {
                    ne += B[x];
                }
                amt[c][i][j] = amt[c][i - 1][j] + amt[c][i][j - 1] - amt[c][i - 1][j - 1] + ne;
            }
        }

        for (int i = 1; i <= N; i++) B[i] = (B[i] + 1) % (C + 1);
    }

    for (int q = 0; q < Q; q++) {
        int t, a, b, c, d;
        cin >> t >> a >> b >> c >> d;
        t = t % (C + 1);
        int ans = amt[t][c][d] - amt[t][c][b - 1] - amt[t][a - 1][d] + amt[t][a - 1][b - 1];
        cout << ans << endl;
    }

    return 0;
}
