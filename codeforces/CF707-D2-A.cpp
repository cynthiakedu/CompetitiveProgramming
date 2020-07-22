#include <bits/stdc++.h>
using namespace std;
int N, M;
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            if (c == 'C' || c == 'M' || c == 'Y') {
                ok = false;
            }
        }
    }
    cout << (ok ? "#Black&White" : "#Color") << endl;
    return 0;
}
