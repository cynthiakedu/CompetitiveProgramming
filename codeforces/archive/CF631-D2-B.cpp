#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, K;
int C[100005];
map<int, int> rm, cm;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= K; i++) {
        int t, idx, c;
        cin >> t >> idx >> c;
        C[i] = c;
        if (t == 1) {
            rm[idx] = i;
        } else {
            cm[idx] = i;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int a = rm[i], b = cm[j];
            cout << C[max(a, b)] << (j == M ? "\n" : " ");
        }
    }

    return 0;
}
