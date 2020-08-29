#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int, int>
const int mxN = 10e5;
int N, M, K, A[mxN + 5], B[mxN + 5];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= M; i++) cin >> B[i];
    sort(A + 1, A + N + 1);
    sort(B + 1, B + M + 1);
    reverse(A + 1, A + N + 1);
    reverse(B + 1, B + M + 1);

    int a = 1, b = 1;

    while (a <= N && b <= M) {
        if (A[a] > B[b]) {
            cout << "YES" << endl;
            return 0;
        }
        a++;
        b++;
    }
    if (a <= N) {
        cout << "YES" << endl;
        return 0;
    }

    cout << "NO" << endl;

    return 0;
}
