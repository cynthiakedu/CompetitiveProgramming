#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, Q, M, val[15];
int arrCt[(1 << 13)];
ii arr2[1 << 13];
int cum[(1 << 12) + 5][(1 << 12) + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> Q;
    for (int i = 0; i < N; i++) {
        cin >> val[N - 1 - i];
    }
    for (int i = 0, x; i < M; i++) {
        string s;
        cin >> s;
        x = stoi(s, 0, 2);
        arrCt[x]++;
    }
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                arr2[i + 1].first += val[j];
            }
        }
        arr2[i + 1].second = i;
    }
    sort(arr2 + 1, arr2 + (1 << N) + 1);

    for (int i = 0; i < (1 << N); i++) {
        for (int j = 1; j <= (1 << N); j++) {
            cum[i][j] = arrCt[i ^ (arr2[j].second)];
            cum[i][j] += cum[i][j - 1];
        }
    }

    for (int q = 0, x, k; q < Q; q++) {
        string s;

        cin >> s;
        for (int i = 0; i < N; i++) {
            s[i] = s[i] == '1' ? '0' : '1';
        }
        x = stoi(s, 0, 2);
        cin >> k;
        int pos = (int)(upper_bound(arr2 + 1, arr2 + (1 << N) + 1, ii{k, INT_MAX}) - arr2);
        cout << cum[x][pos - 1] << "\n";
    }

    return 0;
}
