#include <bits/stdc++.h>
using namespace std;
int N, M, W;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> N >> M >> W;
        if (!N && !M && !W) return 0;
        cout << (((N - 7) * (M - 7) + W) / 2) << endl;
    }
    return 0;
}
