#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int T, N;
int ptr[505], rtp[505];
int ctA[505], ctB[505];
int M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= N; i++) {
            ctA[i] = 0, ctB[i] = 0;
            cin >> rtp[i];
            ptr[rtp[i]] = i;
        }
        cin >> M;
        for (int i = 0, a, b; i < M; i++) {
            cin >> a >> b;
            int idx1 = ptr[a], idx2 = ptr[b];
            ctB[max(idx1, idx2)]++;
            ctA[min(idx1, idx2)]++;
        }
        int ans[505] = {};
        bool possible = true;
        for (int i = 1; i <= N; i++) {
            int b = (i - 1 - ctB[i]) + (ctA[i]);
            int a = (ctB[i]) + (N - i - ctA[i]);
            if (b + a != N - 1 || ans[b + 1] != 0) {
                possible = false;
                break;
            }
            ans[b + 1] = rtp[i];
        }
        if (!possible) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            for (int i = 1; i <= N; i++) cout << ans[i] << (i == N ? "\n" : " ");
        }
    }

    return 0;
}
