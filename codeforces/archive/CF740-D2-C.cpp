#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
int N, M, L, R, X = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> L >> R;
        X = min(X, R - L + 1);
    }
    cout << X << endl;
    for (int i = 0; i < N; i++) {
        cout << i % X << (i == N - 1 ? "\n" : " ");
    }

    return 0;
}
