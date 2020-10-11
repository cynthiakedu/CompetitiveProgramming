#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 10000;
ll MOD = 1e9 + 7;
bool debug = false;

int N = 20, M = 20; //N^2M
int arr[MXN][2];
ll ans;
int cm[MXN][MXN];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);

    // freopen("output.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    srand(time(NULL));

    // cin >> N >> M;
    // for (int i = 1; i <= N; ++i) {
    //     cin >> arr[i][0] >> arr[i][1];
    // }
    cout << N << " " << M << "\n";
    for (int i = 1; i <= N; ++i) {
        arr[i][0] = rand() % M + 1;
        arr[i][1] = rand() % (M - arr[i][0] + 1) + arr[i][0];
        cout << arr[i][0] << " " << arr[i][1] << "\n";
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = arr[i][0]; j <= arr[i][1]; ++j) {
            cm[i][j] = 1;
        }
        for (int j = 1; j <= M; ++j) {
            cm[i][j] += cm[i][j - 1];
        }
    }
    int tmp[MXN][2];
    for (int i = 1; i <= M; ++i) {
        for (int j = i; j <= M; ++j) {
            bool ok = true, hasOne = false;
            for (int k = 1; k <= N; ++k) {
                int x = cm[k][j] - cm[k][i - 1];
                if (x && !(x & 1)) ok = false;
                if (x) hasOne = true;
            }
            if (hasOne && ok) {
                ans += (j - i + 1);
                tmp[i][0]++, tmp[i][1] += (j - i + 1);
            }
        }
    }

    // for (int i = 1; i <= M; ++i) {
    //     fprintf(stderr, "%d: %d %d \n", i, tmp[i][0], tmp[i][1]);
    // }
    fprintf(stderr, "CHECKER ANS: %lld\n", ans);

    return 0;
}