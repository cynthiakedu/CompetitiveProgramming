#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MXN = 100005;
ll MOD = 1e9 + 7;
bool debug = false;

int N = 3000, C = 11;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    freopen("output.txt", "w", stdout);
    srand(time(NULL));

    cout << N << " " << C << "\n";
    for (int i = 1; i <= N; ++i) {
        cout << (rand() % C + 1) << (i == N ? "\n" : " ");
    }


    return 0;
}
