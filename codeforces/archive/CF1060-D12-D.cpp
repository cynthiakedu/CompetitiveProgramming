#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, L[mxN + 5], R[mxN + 5];
ll S = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        S += L[i] + R[i] + 1;
    }
    sort(L + 1, L + N + 1);
    sort(R + 1, R + N + 1);
    for (int i = 1; i <= N; i++) {
        S -= min(L[i], R[i]);
    }
    cout << S << endl;

    return 0;
}
