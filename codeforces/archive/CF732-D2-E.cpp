#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

#define MXN 200005
bool debug = false;

int N, M, match[MXN], usedS[MXN], numS[MXN];
vector<int> c[MXN], s[MXN];
int ans1, ans2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 1, x; i <= N; i++)
        cin >> x, c[i] = {x, i};
    sort(c + 1, c + N + 1);

    for (int i = 1, x; i <= M; i++)
        cin >> x, s[i] = {x, i};
    sort(s + 1, s + M + 1);

    for (int t = 0; t <= 31; t++) {
        for (int j = 1, k = 1; j <= N && k <= M; j++) {
            if (match[c[j][1]]) continue;
            while (k <= M && (usedS[s[k][1]] || s[k][0] < c[j][0])) {
                k++;
            }
            if (k <= M && s[k][0] == c[j][0]) {
                match[c[j][1]] = s[k][1];
                usedS[s[k][1]] = 1;
                ans1++;
                ans2 += numS[s[k][1]];
                k++;
            }
        }
        for (int i = 1; i <= M; i++) {
            if (!usedS[s[i][1]]) {
                numS[s[i][1]]++;
                s[i][0] = (s[i][0] + 1) / 2;
            }
        }
    }
    cout << ans1 << " " << ans2 << "\n";
    for (int i = 1; i <= M; i++) cout << (usedS[i] ? numS[i] : 0) << (i == M ? "\n" : " ");
    for (int i = 1; i <= N; i++) cout << match[i] << (i == N ? "\n" : " ");

    return 0;
}
