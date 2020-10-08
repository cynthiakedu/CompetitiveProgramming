#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    if ((M >= 2 && M - 1 >= N - M) || M == N) {
        cout << M - 1 << endl;
    } else {
        cout << M + 1 << endl;
    }

    return 0;
}
